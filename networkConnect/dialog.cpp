#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   
    if(ui->configurationCombo->currentText() == "Manual")
    {
        ui->automaticFrame->hide();
        ui->manualFrame->show();
    }
    else if(ui->configurationCombo->currentText() == "Automatic")
    {
        ui->manualFrame->hide();
        ui->automaticFrame->show();
        ui->automaticFrame->setGeometry(ui->manualFrame->geometry());
    }
//*******************************************************************
//Scann Wifi Network Available

//*******************************************************************
}
//*******************************************************************
static int
get_info(int			skfd,
     char *			ifname,
     struct wireless_info *	info)
{
  struct iwreq		wrq;

  memset((char *) info, 0, sizeof(struct wireless_info));

  /* Get wireless name */
  if(iw_get_ext(skfd, ifname, SIOCGIWNAME, &wrq) < 0)
    {
      /* If no wireless name : no wireless extensions */
      /* But let's check if the interface exists at all */
      struct ifreq ifr;

      strcpy(ifr.ifr_name, ifname);
      if(ioctl(skfd, SIOCGIFFLAGS, &ifr) < 0)
    return(-ENODEV);
      else
    return(-ENOTSUP);
    }
  else
    {
      strncpy(info->name, wrq.u.name, IFNAMSIZ);
      info->name[IFNAMSIZ] = '\0';
    }

  /* Get ranges */
  if(iw_get_range_info(skfd, ifname, &(info->range)) >= 0)
    info->has_range = 1;

  /* Get network ID */
  if(iw_get_ext(skfd, ifname, SIOCGIWNWID, &wrq) >= 0)
    {
      info->has_nwid = 1;
      memcpy(&(info->nwid), &(wrq.u.nwid), sizeof(iwparam));
    }

  /* Get frequency / channel */
  if(iw_get_ext(skfd, ifname, SIOCGIWFREQ, &wrq) >= 0)
    {
      info->has_freq = 1;
      info->freq = iw_freq2float(&(wrq.u.freq));
    }

  /* Get sensitivity */
  if(iw_get_ext(skfd, ifname, SIOCGIWSENS, &wrq) >= 0)
    {
      info->has_sens = 1;
      memcpy(&(info->sens), &(wrq.u.sens), sizeof(iwparam));
    }

  /* Get encryption information */
  wrq.u.data.pointer = (caddr_t) info->key;
  wrq.u.data.length = IW_ENCODING_TOKEN_MAX;
  wrq.u.data.flags = 0;
  if(iw_get_ext(skfd, ifname, SIOCGIWENCODE, &wrq) >= 0)
    {
      info->has_key = 1;
      info->key_size = wrq.u.data.length;
      info->key_flags = wrq.u.data.flags;
    }

  /* Get ESSID */
  wrq.u.essid.pointer = (caddr_t) info->essid;
  wrq.u.essid.length = IW_ESSID_MAX_SIZE + 1;
  wrq.u.essid.flags = 0;
  if(iw_get_ext(skfd, ifname, SIOCGIWESSID, &wrq) >= 0)
    {
      info->has_essid = 1;
      info->essid_on = wrq.u.data.flags;
    }

  /* Get AP address */
  if(iw_get_ext(skfd, ifname, SIOCGIWAP, &wrq) >= 0)
    {
      info->has_ap_addr = 1;
      memcpy(&(info->ap_addr), &(wrq.u.ap_addr), sizeof (sockaddr));
    }

  /* Get NickName */
  wrq.u.essid.pointer = (caddr_t) info->nickname;
  wrq.u.essid.length = IW_ESSID_MAX_SIZE + 1;
  wrq.u.essid.flags = 0;
  if(iw_get_ext(skfd, ifname, SIOCGIWNICKN, &wrq) >= 0)
    if(wrq.u.data.length > 1)
      info->has_nickname = 1;

  /* Get bit rate */
  if(iw_get_ext(skfd, ifname, SIOCGIWRATE, &wrq) >= 0)
    {
      info->has_bitrate = 1;
      memcpy(&(info->bitrate), &(wrq.u.bitrate), sizeof(iwparam));
    }

  /* Get RTS threshold */
  if(iw_get_ext(skfd, ifname, SIOCGIWRTS, &wrq) >= 0)
    {
      info->has_rts = 1;
      memcpy(&(info->rts), &(wrq.u.rts), sizeof(iwparam));
    }

  /* Get fragmentation threshold */
  if(iw_get_ext(skfd, ifname, SIOCGIWFRAG, &wrq) >= 0)
    {
      info->has_frag = 1;
      memcpy(&(info->frag), &(wrq.u.frag), sizeof(iwparam));
    }

  /* Get operation mode */
  if(iw_get_ext(skfd, ifname, SIOCGIWMODE, &wrq) >= 0)
    {
      info->mode = wrq.u.mode;
      if((info->mode < IW_NUM_OPER_MODE) && (info->mode >= 0))
    info->has_mode = 1;
    }

  /* Get Power Management settings */
  wrq.u.power.flags = 0;
  if(iw_get_ext(skfd, ifname, SIOCGIWPOWER, &wrq) >= 0)
    {
      info->has_power = 1;
      memcpy(&(info->power), &(wrq.u.power), sizeof(iwparam));
    }

#if WIRELESS_EXT > 9
  /* Get Transmit Power */
  if(iw_get_ext(skfd, ifname, SIOCGIWTXPOW, &wrq) >= 0)
    {
      info->has_txpower = 1;
      memcpy(&(info->txpower), &(wrq.u.txpower), sizeof(iwparam));
    }
#endif

#if WIRELESS_EXT > 10
  /* Get retry limit/lifetime */
  if(iw_get_ext(skfd, ifname, SIOCGIWRETRY, &wrq) >= 0)
    {
      info->has_retry = 1;
      memcpy(&(info->retry), &(wrq.u.retry), sizeof(iwparam));
    }
#endif	/* WIRELESS_EXT > 10 */

  /* Get stats */
  if(iw_get_stats(skfd, ifname, &(info->stats)) >= 0)
    {
      info->has_stats = 1;
    }

  return(0);
}

/*------------------------------------------------------------------*/
/*
 * Print on the screen in a neat fashion all the info we have collected
 * on a device.
 */
static void
display_info(struct wireless_info *	info,
         char *			ifname)
{
  char		buffer[128];	/* Temporary buffer */

  /* One token is more of less 5 characters, 14 tokens per line */
  int	tokens = 3;	/* For name */

  /* Display device name and wireless name (name of the protocol used) */
  printf("%-8.8s  %s  ", ifname, info->name);

  /* Display ESSID (extended network), if any */
  if(info->has_essid)
    {
      if(info->essid_on)
    {
      /* Does it have an ESSID index ? */
      if((info->essid_on & IW_ENCODE_INDEX) > 1)
        printf("ESSID:\"%s\" [%d]  ", info->essid,
           (info->essid_on & IW_ENCODE_INDEX));
      else
        printf("ESSID:\"%s\"  ", info->essid);
    }
      else
    printf("ESSID:off/any  ");
    }

  /* Display NickName (station name), if any */
  if(info->has_nickname)
    printf("Nickname:\"%s\"", info->nickname);

  /* Formatting */
  if(info->has_essid || info->has_nickname)
    {
      printf("\n          ");
      tokens = 0;
    }

  /* Display Network ID */
  if(info->has_nwid)
    {
      /* Note : should display proper number of digit according to info
       * in range structure */
      if(info->nwid.disabled)
    printf("NWID:off/any  ");
      else
    printf("NWID:%X  ", info->nwid.value);
      tokens +=2;
    }

  /* Display the current mode of operation */
  if(info->has_mode)
    {
      printf("Mode:%s  ", iw_operation_mode[info->mode]);
      tokens +=3;
    }

  /* Display frequency / channel */
  if(info->has_freq)
    {
      iw_print_freq(buffer, info->freq);
      printf("%s  ", buffer);
      tokens +=4;
    }

  /* Display the address of the current Access Point */
  if(info->has_ap_addr)
    {
      /* A bit of clever formatting */
      if(tokens > 8)
    {
      printf("\n          ");
      tokens = 0;
    }
      tokens +=6;

      /* Oups ! No Access Point in Ad-Hoc mode */
      if((info->has_mode) && (info->mode == IW_MODE_ADHOC))
    printf("Cell:");
      else
    printf("Access Point:");
      printf(" %s  ", iw_pr_ether(buffer, (const unsigned char *)info->ap_addr.sa_data));
    }

  /* Display the currently used/set bit-rate */
  if(info->has_bitrate)
    {
      /* A bit of clever formatting */
      if(tokens > 11)
    {
      printf("\n          ");
      tokens = 0;
    }
      tokens +=3;

      /* Display it */
      iw_print_bitrate(buffer, info->bitrate.value);
      printf("Bit Rate%c%s   ", (info->bitrate.fixed ? '=' : ':'), buffer);
    }

#if WIRELESS_EXT > 9
  /* Display the Transmit Power */
  if(info->has_txpower)
    {
      /* A bit of clever formatting */
      if(tokens > 11)
    {
      printf("\n          ");
      tokens = 0;
    }
      tokens +=3;

      /* Disabled ? */
      if(info->txpower.disabled)
    printf("Tx-Power:off   ");
      else
    {
      int		dbm;

      /* Fixed ? */
      if(info->txpower.fixed)
        printf("Tx-Power=");
      else
        printf("Tx-Power:");

      /* Convert everything to dBm */
      if(info->txpower.flags & IW_TXPOW_MWATT)
        dbm = iw_mwatt2dbm(info->txpower.value);
      else
        dbm = info->txpower.value;

      /* Display */
      printf("%d dBm   ", dbm);
    }
    }
#endif

  /* Display sensitivity */
  if(info->has_sens)
    {
      /* A bit of clever formatting */
      if(tokens > 10)
    {
      printf("\n          ");
      tokens = 0;
    }
      tokens +=4;

      /* Fixed ? */
      if(info->sens.fixed)
    printf("Sensitivity=");
      else
    printf("Sensitivity:");

      if(info->has_range)
    /* Display in dBm ? */
    if(info->sens.value < 0)
      printf("%d dBm  ", info->sens.value);
    else
      printf("%d/%d  ", info->sens.value, info->range.sensitivity);
      else
    printf("%d  ", info->sens.value);
    }

  printf("\n          ");
  tokens = 0;

#if WIRELESS_EXT > 10
  /* Display retry limit/lifetime information */
  if(info->has_retry)
    {
      printf("Retry");
      /* Disabled ? */
      if(info->retry.disabled)
    printf(":off");
      else
    {
      /* Let's check the value and its type */
      if(info->retry.flags & IW_RETRY_TYPE)
        {
          iw_print_retry_value(buffer,
                   info->retry.value, info->retry.flags);
          printf("%s", buffer);
        }

      /* Let's check if nothing (simply on) */
      if(info->retry.flags == IW_RETRY_ON)
        printf(":on");
    }
      printf("   ");
      tokens += 5;	/* Between 3 and 5, depend on flags */
    }
#endif	/* WIRELESS_EXT > 10 */

  /* Display the RTS threshold */
  if(info->has_rts)
    {
      /* Disabled ? */
      if(info->rts.disabled)
    printf("RTS thr:off   ");
      else
    {
      /* Fixed ? */
      if(info->rts.fixed)
        printf("RTS thr=");
      else
        printf("RTS thr:");

      printf("%d B   ", info->rts.value);
    }
      tokens += 3;
    }

  /* Display the fragmentation threshold */
  if(info->has_frag)
    {
      /* A bit of clever formatting */
      if(tokens > 10)
    {
      printf("\n          ");
      tokens = 0;
    }
      tokens +=4;

      /* Disabled ? */
      if(info->frag.disabled)
    printf("Fragment thr:off");
      else
    {
      /* Fixed ? */
      if(info->frag.fixed)
        printf("Fragment thr=");
      else
        printf("Fragment thr:");

      printf("%d B   ", info->frag.value);
    }
    }

  /* Formating */
  if(tokens > 0)
    printf("\n          ");

  /* Display encryption information */
  /* Note : we display only the "current" key, use iwlist to list all keys */
  if(info->has_key)
    {
      printf("Encryption key:");
      if((info->key_flags & IW_ENCODE_DISABLED) || (info->key_size == 0))
    printf("off\n          ");
      else
    {
      /* Display the key */
      iw_print_key(buffer, info->key, info->key_size, info->key_flags);
      printf("%s", buffer);

      /* Other info... */
      if((info->key_flags & IW_ENCODE_INDEX) > 1)
        printf(" [%d]", info->key_flags & IW_ENCODE_INDEX);
      if(info->key_flags & IW_ENCODE_RESTRICTED)
        printf("   Encryption mode:restricted");
      if(info->key_flags & IW_ENCODE_OPEN)
        printf("   Encryption mode:open");
      printf("\n          ");
    }
    }

  /* Display Power Management information */
  /* Note : we display only one parameter, period or timeout. If a device
   * (such as HiperLan) has both, the user need to use iwlist... */
  if(info->has_power)	/* I hope the device has power ;-) */
    {
      printf("Power Management");
      /* Disabled ? */
      if(info->power.disabled)
    printf(":off\n          ");
      else
    {
      /* Let's check the value and its type */
      if(info->power.flags & IW_POWER_TYPE)
        {
          iw_print_pm_value(buffer, info->power.value, info->power.flags);
          printf("%s  ", buffer);
        }

      /* Let's check the mode */
      iw_print_pm_mode(buffer, info->power.flags);
      printf("%s", buffer);

      /* Let's check if nothing (simply on) */
      if(info->power.flags == IW_POWER_ON)
        printf(":on");
      printf("\n          ");
    }
    }

  /* Display statistics */
  if(info->has_stats)
    {
      info->stats.qual.updated = 0x0;	/* Not that reliable, disable */
      iw_print_stats(buffer, &info->stats.qual, &info->range, info->has_range);
      printf("Link %s\n", buffer);

#if WIRELESS_EXT > 11
      printf("          Rx invalid nwid:%d  Rx invalid crypt:%d  Rx invalid frag:%d\n          Tx excessive retries:%d  Invalid misc:%d   Missed beacon:%d\n",
         info->stats.discard.nwid,
         info->stats.discard.code,
         info->stats.discard.fragment,
         info->stats.discard.retries,
         info->stats.discard.misc,
         info->stats.miss.beacon);
#else /* WIRELESS_EXT > 11 */
      printf("          Rx invalid nwid:%d  invalid crypt:%d  invalid misc:%d\n",
         info->stats.discard.nwid,
         info->stats.discard.code,
         info->stats.discard.misc);
#endif /* WIRELESS_EXT > 11 */
    }

  printf("\n");
}

/*------------------------------------------------------------------*/
/*
 * Print on the screen in a neat fashion all the info we have collected
 * on a device.
 */
static int
print_info(int		skfd,
       char *	ifname,
       char *	args[],
       int		count)
{
  struct wireless_info	info;
  int			rc;

  /* Avoid "Unused parameter" warning */
  args = args; count = count;

  rc = get_info(skfd, ifname, &info);
  switch(rc)
    {
    case 0:	/* Success */
      /* Display it ! */
      display_info(&info, ifname);
      break;

    case -ENOTSUP:
      fprintf(stderr, "%-8.8s  no wireless extensions.\n\n",
          ifname);
      break;

    default:
      fprintf(stderr, "%-8.8s  %s\n\n", ifname, strerror(-rc));
    }
  return(rc);
}

//*******************************************************************
int iwconfig()
{
      int sock;

      static const int families[] = {
        AF_INET, AF_IPX, AF_AX25, AF_APPLETALK
      };

      for(int i = 0; i < sizeof(families)/sizeof(int); ++i){
          sock = socket(families[i], SOCK_DGRAM, 0);
      }


      if(sock < 0){
        perror("socket");
        exit(-1);
      }

//      void
//      iw_enum_devices(int		skfd,
//              iw_enum_handler fn,
//              char *		args[],
//              int		count)
//      {

char buff[1024];
FILE *	fh;
struct ifconf ifc;
struct ifreq *ifr;

      #ifndef IW_RESTRIC_ENUM
        /* Check if /proc/net/wireless is available */
        fh = fopen(PROC_NET_DEV, "r");
      #else
        /* Check if /proc/net/wireless is available */
        fh = fopen(PROC_NET_WIRELESS, "r");
      #endif

        if(fh != NULL)
        {
           fgets(buff, sizeof(buff), fh);
           fgets(buff, sizeof(buff), fh);

           while(fgets(buff, sizeof(buff), fh))
           {
              char	name[IFNAMSIZ + 1];
              char *s;

                /* Extract interface name */
                //s = iw_get_ifname(name, sizeof(name), buff);

              int tem = 0;
              while(isspace(*(buff + tem)))
                tem++;

                #ifndef IW_RESTRIC_ENUM
                  /* Get name up to the last ':'. Aliases may contain ':' in them,
                   * but the last one should be the separator */
                  s = strrchr(buff, ':');
                #else
                  /* Get name up to ": "
                   * Note : we compare to ": " to make sure to process aliased interfaces
                   * properly. Doesn't work on /proc/net/dev, because it doesn't guarantee
                   * a ' ' after the ':'*/
                  s = strstr(buff, ": ");
                #endif

                  /* Not found ??? To big ??? */
                  if((s == NULL) || (((s - buff) + 1) > sizeof(name)))
                    return(NULL);

                  /* Copy */
                  memcpy(name, buff, (s - buff));
                  name[s - buff] = '\0';

                  //return(end + 2);
                  strcpy(s,s+2);


            if(!s)
            {
              /* Failed to parse, complain and continue */
              fprintf(stderr, "Cannot parse " PROC_NET_WIRELESS "\n");
            }
            else
            {
              /* Got it, print info about this interface */
              print_info(sock, name, NULL, 0);
            }
          }

            fclose(fh);
          }
        else
          {
            /* Get list of configured devices using "traditional" way */
            ifc.ifc_len = sizeof(buff);
            ifc.ifc_buf = buff;
            if(ioctl(sock, SIOCGIFCONF, &ifc) < 0)
            {
              fprintf(stderr, "SIOCGIFCONF: %s\n", strerror(errno));
              return -1;
            }
            ifr = ifc.ifc_req;

            /* Print them */
            for(int i = ifc.ifc_len / sizeof(struct ifreq); --i >= 0; ifr++)
            print_info(sock, ifr->ifr_name, NULL, 0);
          }

      close(sock);
}

//static int
//print_info(int		skfd,
//	   char *	ifname,
//	   char *	args[],
//	   int		count)
//{
//  struct wireless_info	info;
//  int			rc;

//  /* Avoid "Unused parameter" warning */
//  args = args; count = count;

//  rc = get_info(skfd, ifname, &info);
//  switch(rc)
//    {
//    case 0:	/* Success */
//      /* Display it ! */
//      display_info(&info, ifname);
//      break;

//    case -ENOTSUP:
//      fprintf(stderr, "%-8.8s  no wireless extensions.\n\n",
//	      ifname);
//      break;

//    default:
//      fprintf(stderr, "%-8.8s  %s\n\n", ifname, strerror(-rc));
//    }
//  return(rc);
//}


//*******************************************************************
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_configurationCombo_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Manual")
    {
        ui->automaticFrame->hide();
        ui->manualFrame->show();
    }
    else if(arg1 == "Automatic")
    {
        ui->manualFrame->hide();
        ui->automaticFrame->show();
        ui->automaticFrame->setGeometry(ui->manualFrame->geometry());
    }








}

void Dialog::on_connectPushButton_clicked()
{

}

void Dialog::on_connectWireless_clicked()
{

}
