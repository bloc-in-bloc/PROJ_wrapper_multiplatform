#if defined(_WIN32)
#if !defined(DLL_EXPORT_MACRO)
    #define DLL_EXPORT_MACRO __declspec(dllimport)
  #endif
#elif defined(__ANDROID__)
#define DLL_EXPORT_MACRO __attribute__((visibility("default")))
#else
#define DLL_EXPORT_MACRO
#endif

#include "proj.h"

#ifdef __cplusplus
extern "C" {
#endif

class ProjWrapper{
public :
    double ToDeg(const double &deg) {
        return proj_todeg(deg);
    }
};

DLL_EXPORT_MACRO double projToDeg(double angleInRad) {
    return proj_todeg(angleInRad);
}

DLL_EXPORT_MACRO ProjWrapper* CreateNativeObject()
{
    ProjWrapper* obj = new ProjWrapper();
    // you might want to store the object reference on the native side for tracking
    return obj;
}
DLL_EXPORT_MACRO void DestroyNativeObject(ProjWrapper* obj)
{
    // may need to update your tracking in native code
    delete obj;
}

DLL_EXPORT_MACRO double NativeObjectToDeg(ProjWrapper* obj, double deg)
{
    return obj->ToDeg(deg);
}

#ifdef __cplusplus
}
#endif
