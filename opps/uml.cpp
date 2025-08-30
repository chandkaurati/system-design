// take parent CAR class create tow instnaces of this
// electric and manual via inheritance or composistions
// represent this using uml digrams

#include <iostream>
using namespace std;

class Car
{

protected:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;

public:
  Car(string brand, string model)
  {
    this->brand = brand;
    this->model = model;

    isEngineOn = false;
    currentSpeed = 0;
  };

  // comon methods for all cars

  void startEngine()
  {
    isEngineOn = true;
    cout << "Engine stared" << endl;
  };

  void stopeEngine()
  {
    isEngineOn = false;
    cout << "Engine Stopped" << endl;
  }

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << " Cannot accelerate ! Car's engine is off" << endl;
      return;
    };

    currentSpeed += 20;
    cout << " accelerating to" << currentSpeed << " km/h " << endl;
  };

  void brake()
  {
    if (currentSpeed == 0)
      currentSpeed = 0;
    currentSpeed -= 20;
    cout << " Braking ! Speed is now " << currentSpeed << endl;
  };
};

class ManualCar : public Car
{
private:
  int currentGear;

public:
  ManualCar(string brand, string model) : Car(brand, model)
  {
    currentGear = 0;
  };

  void shiftGear(int gear)
  {
    currentGear = gear;
    cout << " gear shifted to " << currentGear << endl;
  };
};


class electricCar: public Car{
  private : 
     int battry;

  public:
  electricCar(string brand, string model): Car(brand, model){
      battry = 100;
  };


  void chargeBattery(){
    if(battry == 100){
      cout<< " Battry is already full ";      
    };
    battry = 100;
  }


};





int main()
{

  ManualCar* mymanualCar = new ManualCar("Suzuki", "Swift");

  mymanualCar->startEngine();
  mymanualCar->shiftGear(1);
  mymanualCar->accelerate();
  mymanualCar->shiftGear(2);
  mymanualCar->accelerate();
  mymanualCar->brake();
  mymanualCar->stopeEngine();
  
  delete mymanualCar;

  return 0;
}
