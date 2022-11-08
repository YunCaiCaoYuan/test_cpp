#include <iostream>
#include <string>
using namespace std;

class Patient{
public:
//    (1) virtual string getName()=0;
//    virtual string getName()=0;
    virtual string getName() {return "";};
};

// 这两种写法都可以编译通过，虚函数和纯虚函数

class Disposer{
public:
//    (2) virtual void dispose(Patient *patient)=0;
//    virtual void dispose(Patient *patient)=0;
    virtual void dispose(Patient *patient){};
};

class Registry:public Disposer{ // 挂号
public:
    void dispose(Patient *patient) {
        cout<<"I am registering..."<<patient->getName()<<endl;
    }
};

class Doctor:public Disposer { // 门诊
public:
    void dispose(Patient *patient) {
        cout<<"I am giving diagnosing..."<<patient->getName()<<endl;
    }
};

class Facade{
private:
    Patient *patient;
public:
    Facade(Patient *patient) {
        this->patient= patient;
    }
    void dispose() {
        Registry *registry=new Registry();
        Doctor * doctor = new Doctor();

        registry->dispose(patient);
        doctor->dispose(patient);
    }
};

class ConcretePatient: public Patient{
private:
    string name;
public:
    ConcretePatient(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};

int main() {
    Patient * patient = new ConcretePatient(""); // (3) new ConcretePatient("")
    Facade * f = new Facade(patient);                 //  (4) Facade * (5) new Facade(patient)
    f->dispose();                                     //  (6) f->dispose()
    return 0;
}