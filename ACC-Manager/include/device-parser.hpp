#ifndef _ACC_MANAGER_DEVICE_PARSER
#define _ACC_MANAGER_DEVICE_PARSER

#ifdef VERBOSE
#define ACC_VERBOSE true
#else
#define ACC_VERBOSE false
#endif

#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <regex>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "device.pb.h"
#include "common.hpp"
#include "utils.hpp"
#include <sys/utsname.h>

// Device parser for parsing user-defined pass through configuration
class DeviceParser{
public:
    DeviceParser(char*, char*);
    bool parse(list<Accelerator>*);
    bool parse(list<Accelerator>*,const char*);
private:
    char* statusFilePath;
    char* deviceFilePath;

    list<Accelerator> protoToAccelerator(device::accelerator_list*);    // For user-specified file
    list<Device> protoToDeviceList(const device::device_list*);            // For status file
    Device protoToDevice(const device::device*);
    map<string,Device> devListToDevMap(list<Device>);
    bool isListValid(list<Accelerator>&);
    bool isAcceleratorValid(Accelerator&);
    bool isDeviceValid(Device&);

    set<string> deviceNamesTmp;
    string ld_cache;
    string machine_arch;
};
#endif
