# hackNJIT-TTYR
just a small hackathon project for hacknjit
used a adafruit thermal printer usb connected to a raspberry pi and using dev/usb/lp0 to write command and terminal output to the serial printer
# UPDATE 1
got rid of some dudes easy library for system termial output
instead I found out i can just pipe termial output to a file that i then send to a printer, probably could send directly to printer later
also commands run in bash now and not sh as a quick workaround