#ifndef _ACC_MANAGER_MOUNTER
#define _ACC_MANAGER_MOUNTER

#include "utils.hpp"

#include <sys/mount.h>
#include <sys/types.h>

#include <sched.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <fstream>

#define ERR_CODE_ONLY_ABS_PATH_ALLOWED 31

// Mounter class for mounting needed files to container
class Mounter{
    public:
        explicit Mounter(Context*);
        bool mountDevices(list<Device>);
        bool mountDevice(Device);
    private:
        Context* cont;
        bool mountDeviceFiles(list<string>);
        bool mountDeviceFile(string, string);
        bool mountLibraries(list<string>);
        bool mountLibrary(string);
        bool mountFiles(list<array<string,2>>);
        bool mountFile(string,string);
        bool setEnvs(list<array<string,2>>);

        bool createDev(string,struct stat);
};

#endif