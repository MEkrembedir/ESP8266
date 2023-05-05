# ESP8266
#EN
This code creates a web server using ESP8266 WiFi module and sets the module as an access point.

The following libraries are used in this code:

ESP8266WiFi: Library used to establish a Wi-Fi connection for ESP8266 WiFi module.
WiFiClient: Library used for the web server.
ESP8266WebServer: Library used to create a web server on the ESP8266 module.
First, the ESP8266 module is configured as an access point using the "local_IP", "gateway", and "subnet" variables.

Next, the "ssid" and "password" variables are used to set the module as a Wi-Fi access point.

Then, a route is defined for the root page. When this route is accessed, an HTML page is created and sent as a response by the server. This HTML page provides users with the information needed to connect to the Wi-Fi network, including the SSID and password.

Finally, the server is started and server requests are processed in the "loop" function. Server requests are processed using the "handleClient" function, ensuring that the server works properly.

#TR
Bu kod ESP8266 WiFi modülü kullanılarak bir web sunucusu oluşturur ve modülü bir access point olarak ayarlar.

Bu kodda kullanılan kütüphaneler:

ESP8266WiFi: ESP8266 WiFi modülü için Wi-Fi bağlantısı kurmak için kullanılan kütüphane.
WiFiClient: Web sunucusu için kullanılan kütüphane.
ESP8266WebServer: ESP8266 modülü üzerinde bir web sunucusu oluşturmak için kullanılan kütüphane.
İlk olarak, "local_IP", "gateway" ve "subnet" değişkenleri kullanılarak ESP8266 modülü access point olarak yapılandırılır.

Daha sonra "ssid" ve "password" değişkenleri kullanılarak modülün Wi-Fi access point olarak çalışması sağlanır.

Ardından, root sayfası için bir route tanımlanır. Bu route'a erişildiğinde, bir HTML sayfası oluşturulur ve sunucu yanıt olarak bu sayfayı gönderir. Bu HTML sayfası, kullanıcılara Wi-Fi ağına bağlanmak için gereken bilgileri (SSID ve şifre) sağlar.

Son olarak, sunucu başlatılır ve "loop" fonksiyonu içinde sunucu istekleri işlenir. Sunucuya gelen istekleri "handleClient" fonksiyonu ile işleyerek, sunucunun doğru çalışmasını sağlanır.
