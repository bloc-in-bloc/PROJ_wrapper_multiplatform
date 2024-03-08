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

DLL_EXPORT_MACRO double projToDeg(double angleInRad) {
    return proj_todeg(angleInRad);
}

#ifdef __cplusplus
}
#endif
