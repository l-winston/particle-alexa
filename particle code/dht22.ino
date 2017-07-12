// This #include statement was automatically added by the Particle IDE.
#include "PietteTech_DHT.h"

#define DHTPIN          D7
#define DHTTYPE         DHT22

#define DELAY           5000

PietteTech_DHT dht(DHTPIN, DHTTYPE);
int temperature = 0;
int humidity = 0;

// Returns temperature
int getTemperature(String args){
    return temperature;
}

// Returns humidity
int getHumidity(String args){
    return humidity;
}


void setup() {
    Serial.begin(115200);
    dht.begin();
    
    pinMode(D2, OUTPUT);
    pinMode(D6, OUTPUT);
    
    // Particle Functions
    Spark.function("gettmp", getTemperature);
    Spark.function("gethmd", getHumidity);
}

void loop() {
    // Get temperature and humidity
    temperature = (int)dht.readTemperature();
    humidity = (int)dht.readHumidity();
    
    Serial.println();
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println();
    
    delay(DELAY);
}