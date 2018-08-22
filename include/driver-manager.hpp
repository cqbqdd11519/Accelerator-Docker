#ifndef _ACC_MANAGER_DRIVER_MANAGER
#define _ACC_MANAGER_DRIVER_MANAGER

#include "common.hpp"

class DriverManager{
    public:
        DriverManager();
        bool switchDriver(Device device, Driver target);
        list<Device> getAllDevices();
        list<Driver> getAllDrivers();
    private:
        list<Device> devices;
        list<Driver> drivers;
};

#endif