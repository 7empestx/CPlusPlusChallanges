#include <iostream>

using namespace std;

class Vehicle {
  public:
    Vehicle(const string& plate, const string& brand, unsigned year)
      : licensePlate(plate), brand(brand), modelYear(year) {}

    virtual void start() {
      cout << "Vehicle Starting" << endl;
    }
    virtual void stop() {
      cout << "Vehicle Stopping" << endl;
    }
    virtual ~Vehicle() {}

  protected:
    string licensePlate;
    string brand;
    unsigned modelYear;
};

class Truck : public Vehicle {
  public:
    Truck(const string &plate, const string& brand, unsigned year, unsigned payload)
      : Vehicle(plate, brand, year), payloadCapacity(payload) {}
  void start() override {
    cout << "Truck strarting with payload capacity " << payloadCapacity << endl;
  }
  private:
    unsigned payloadCapacity;
};

class Car: public Vehicle {
  public:
    Car(const string &plate, const string& brand, unsigned year, string chargerType)
      : Vehicle(plate, brand, year), chargerType(chargerType) {}
  void start() override {
    cout << "Car strarting with charger type " << chargerType << endl;
  }
  private:
    string chargerType; 
};

class Motorcycle: public Vehicle {
  public:
    Motorcycle(const string &plate, const string& brand, unsigned year, string sideCar)
      : Vehicle(plate, brand, year), sideCar(sideCar) {}
  void start() override {
    cout << "Motorcycle strarting with side car " << sideCar << endl;
  }
  string sideCar; 
};

int main() {
  Truck t("Hello World", "Ford", 2024, 1000);
  Car c("Goodbye World", "Tesla", 2017, "super");
  Motorcycle m("Foo Bar", "Hyabusa", 2018, "1 seater");

  t.start();
  c.start();
  m.start();

  return 0;
}
