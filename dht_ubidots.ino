#include <DHT.h>
#include <UbidotsMicroESP8266.h>

#define DHTPIN 4
#define DHTTYPE DHT11

//bisa dimasukkan di akhir sesi
char auth[] = "*******";
char ssid[] = "ssidhotspotmu";
char pass[] = "passwordhotspotmu";¥

DHT dht(DHTPIN, DHTTYPE);
Ubidots client(auth);
unsigned long last = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  delay(20)
  client.wifiConnection(ssid,pass) //menyawmbungkan Ubidots dengan wifi
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-last>10000){ //jika sudah 10 detik
    float hum = =dht.readHumidity();
    float temp = dht.readTemperature();

    last = millis();
    client.add("kelembapan", hum);
    client.add("Temperature",temp);  

    client.sendAll(true);
    }
}
