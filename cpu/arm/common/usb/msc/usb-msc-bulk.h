#ifndef __USB_MSC_BULK_H__SHSP6ONHDJ__
#define __USB_MSC_BULK_H__SHSP6ONHDJ__

#include <usb.h>
#include <stdint.h>

#define USB_MSC_BUFFERS 4

/*  Communication Class */
/* Class code */
#define MASS_STORAGE  0x08

/* Interface subclass codes */
#define MASS_RBC 0x01
#define MASS_SFF_8020i 0x02
#define MASS_MMC_2 0x02
#define MASS_QIC_157 0x03
#define MASS_UFI 0x04
#define MASS_SFF_8070i 0x05
#define MASS_SCSI_TRANSP 0x06

/* Protocols */
#define MASS_CBI_COMPLETION 0x00
#define MASS_CBI_NO_COMPLETION 0x01
#define MASS_BULK_ONLY 0x50

/* Requests */
#define MASS_BULK_RESET 0xff
#define MASS_BULK_GET_MAX_LUN 0xfe

#define MASS_BULK_CBW_SIGNATURE  0x43425355
#define MASS_BULK_CSW_SIGNATURE  0x53425355

#define MASS_BULK_CBW_FLAG_IN 0x80

#define MASS_BULK_CSW_STATUS_PASSED 0x00
#define MASS_BULK_CSW_STATUS_FAILED 0x01
#define MASS_BULK_CSW_STATUS_PHASE_ERROR 0x02

struct usb_msc_bulk_cbw
{
  uint32_t dCBWSignature;
  uint32_t dCBWTag;
  uint32_t dCBWDataTransferLength;
  uint8_t bmCBWFlags;
  uint8_t bCBWLUN;
  uint8_t bCBWCBLength;
  uint8_t CBWCB[16];
} BYTE_ALIGNED;

struct usb_msc_bulk_csw
{
  uint32_t dCSWSignature;
  uint32_t dCSWTag;
  uint32_t dCSWDataResidue;
  uint8_t bCSWStatus;
} BYTE_ALIGNED;

struct usb_msc_command_state
{
  const uint8_t *command;
  unsigned int command_length;
  unsigned int status;
  /* Number of data bytes received or sent */
  unsigned int cmd_data_transfered; 
  /* Number of data bytes submitted for transmition or reception */
  unsigned int cmd_data_submitted;
  /* Set by command handler or callback */
  void (*data_cb)(struct usb_msc_command_state *state); /* May be NULL */
};

void
usb_msc_bulk_setup();

typedef enum {
  USB_MSC_HANDLER_OK = 0,
  USB_MSC_HANDLER_DELAYED,
  USB_MSC_HANDLER_FAILED
} usb_msc_handler_status;

usb_msc_handler_status
usb_msc_handle_command(struct usb_msc_command_state *state);
     
void
usb_msc_command_handler_init();

/* Call data_cb when this data has been sent or received */
#define USB_MSC_DATA_DO_CALLBACK 0x20

/* Actually send the data, not just buffer it */
#define USB_MSC_DATA_SEND 0x40

/* Actually receive the data, not just queue buffers for it */
#define USB_MSC_DATA_RECEIVE 0x40

/* The command don't want to send or receive anymore data */
#define USB_MSC_DATA_LAST 0x80

/* Submit a buffer with data to send to the host. Use a callback to be
   notified when data has been sent. Data is not copied so it must
   remain constant while sending. */
void
usb_msc_send_data(const uint8_t *data, unsigned int len, unsigned int flags);

/* Same as usb_msc_send_data but allows one to set additional flags
   in USBBuffer */
void
usb_msc_send_data_buf_flags(const uint8_t *data, unsigned int len,
			    unsigned int flags, uint16_t buf_flags);

#define USB_MSC_SEND_ABORT() \
usb_msc_send_data_buf_flags(NULL, 0, USB_MSC_DATA_LAST, 0)

/* Submit a buffer for receiving data from the host. Use a callback to
   be notified when data has arrived. */
void
usb_msc_receive_data(uint8_t *data, unsigned int len, unsigned int flags);

/* Same as usb_msc_receive_data but allows one to set additional flags
   in USBBuffer */
void
usb_msc_receive_data_buf_flags(uint8_t *data, unsigned int len,
			       unsigned int flags, uint16_t buf_flags);
#define USB_MSC_RECEIVE_ABORT() \
  usb_msc_receive_data_buf_flags(NULL, 0, USB_MSC_DATA_LAST, 0)

#define USB_MSC_DONE() \
  usb_msc_send_data_buf_flags(NULL, 0, USB_MSC_DATA_LAST, 0)



#endif /* __USB_MSC_BULK_H__SHSP6ONHDJ__ */
