# Atreus clone with IBM TrackPoint

Build files and photos:
---
https://github.com/jbro/atreus_tp-case

Build:
---
docker run -e keymap=jbr -e subproject='' -e keyboard=handwired/atreus_tp --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware

Flash:
---
avrdude -v -patmega32u4 -cavr109 -P/dev/cu.usbmodem1421 -b57600 -D -Uflash:w:handwired_atreus_tp_jbr.hex:i
