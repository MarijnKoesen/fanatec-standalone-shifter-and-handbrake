#include <usb_names.h>

#define MANUFACTURER_NAME  {'F','a','n','a','t','e','c'}
#define MANUFACTURER_NAME_LEN 7

#define PRODUCT_NAME    {'S', 'h', 'i', 'f', 't', 'e', 'r', ' ', '&', ' ', 'H', 'a', 'n', 'd',  'b', 'r', 'a', 'k', 'e'}
#define PRODUCT_NAME_LEN  19

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
  2 + MANUFACTURER_NAME_LEN * 2,
  3,
  MANUFACTURER_NAME
};

struct usb_string_descriptor_struct usb_string_product_name = {
  2 + PRODUCT_NAME_LEN * 2,
  3,
  PRODUCT_NAME
};
