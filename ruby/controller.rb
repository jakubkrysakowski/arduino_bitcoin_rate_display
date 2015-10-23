require 'rubygems'  
require 'serialport' # use Kernel::require on windows, works better.  
#require 'net/http'
#require 'uri'
require 'open-uri'
require 'json'

#params for serial port  
url = 'https://www.bitmarket.pl/json/BTCPLN/ticker.json'
port_str = "/dev/ttyUSB2"  #may be different for you  
baud_rate = 9600  
data_bits = 8  
stop_bits = 1  
parity = SerialPort::NONE  

sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)  

#just write forever  
while true do  
  open(url) {|f|  #url must specify the protocol
    content = f.read()
    data = JSON.parse(content)
    sp.write(data["last"])
  }


  sleep 2
end
