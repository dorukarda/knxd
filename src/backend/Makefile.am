if HAVE_FT12
FT12 = ft12.h ft12.cpp lowlatency.h lowlatency.cpp
else
FT12 =
endif

if HAVE_TPUART
TPUART_COMMON = tpuart.h tpuart.cpp
else
TPUART_COMMON = 
endif

if HAVE_TPUARTs
TPUART_SERIAL = tpuartserial.h tpuartserial.cpp lowlatency.h lowlatency.cpp
else
TPUART_SERIAL =
endif

if HAVE_TPUARTs_TCP
TPUART_TCP = tpuarttcp.h tpuarttcp.cpp
else
TPUART_TCP =
endif

if HAVE_EIBNETIP
EIBNETIP = eibnetrouter.h eibnetrouter.cpp
else
EIBNETIP =
endif

if HAVE_EIBNETIPTUNNEL
EIBNETIPTUNNEL = eibnettunnel.h eibnettunnel.cpp
else
EIBNETIPTUNNEL =
endif

if HAVE_USB
USB = usbif.h usbif.cpp
else
USB =
endif

if HAVE_NCN5120
NCN5120 = ncn5120.h ncn5120.cpp
else
NCN5120 = 
endif

if HAVE_DUMMY
DUMMY = dummy.h dummy.cpp
else
DUMMY =
endif

noinst_LIBRARIES = libbackend.a
AM_CPPFLAGS=-I$(top_srcdir)/src/libserver -I$(top_srcdir)/src/common -I$(top_srcdir)/src/usb $(LIBUSB_CFLAGS)

libbackend_a_SOURCES= $(FT12) $(TPUART_COMMON) $(TPUART_SERIAL) $(TPUART_TCP) $(EIBNETIP) $(EIBNETIPTUNNEL) $(USB) $(NCN5120) $(DUMMY) dummy.cpp nat.cpp

