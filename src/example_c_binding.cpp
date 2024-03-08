#if defined(_WIN32)
  #if !defined(EXAMPLE_UNITY_API)
    #define EXAMPLE_UNITY_API __declspec(dllimport)
  #endif
#elif defined(__ANDROID__)
  #define EXAMPLE_UNITY_API __attribute__((visibility("default")))
#else
  #define EXAMPLE_UNITY_API
#endif

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

EXAMPLE_UNITY_API int exampleMethod() {
    return 1;
}

#ifdef __cplusplus
}
#endif
