#ifndef __BRIDGE_C_API_H__
#define __BRIDGE_C_API_H__

#include "HMD.h"
#include "Oculus.h"
#include "Debug.h"

#if defined(_WIN32)
#define EXPORT_LIB extern "C" __declspec(dllexport)
#else
#define EXPORT_LIB extern "C"
#endif

/* Debug wrapper */
EXPORT_LIB Debug *Debug_new(int number) { return new Debug(number); }
EXPORT_LIB void Debug_del(Debug *debug) { if (debug) { delete debug; debug = NULL; } }
EXPORT_LIB int Debug_multiplicationFactor() { return Debug::multiplicationFactor(); }
EXPORT_LIB int Debug_multiplicationResult(Debug *debug) { return debug->multiplicationResult(); }
EXPORT_LIB void Debug_matrix(float *r_float) { Debug::matrix(r_float);}
EXPORT_LIB void Debug_matrixNonStatic(Debug *debug, float *r_float) { debug->matrixNonStatic(r_float); }

/* Oculus wrapper */
EXPORT_LIB bool Oculus_initializeLibrary(){ return Oculus::initializeLibrary(); }
EXPORT_LIB Oculus *Oculus_new(){ return new Oculus(); }
EXPORT_LIB void Oculus_del(Oculus *oculus){ if (oculus) delete oculus; }
EXPORT_LIB bool Oculus_setup(Oculus *oculus, const unsigned int framebuffer_object_left, const unsigned int framebuffer_object_right){ return oculus->setup(framebuffer_object_left, framebuffer_object_right); }
EXPORT_LIB bool Oculus_update(Oculus *oculus, float *r_head_transform[4][4], float *r_eye_left[3], float *r_eye_right[3]) { return oculus->update(r_head_transform, r_eye_left, r_eye_right); }
EXPORT_LIB bool Oculus_frameReady(Oculus *oculus) { return oculus->frameReady(); }
EXPORT_LIB bool Oculus_reCenter(Oculus *oculus) { return oculus->reCenter(); }
EXPORT_LIB unsigned int Oculus_widthLeft(Oculus *oculus) { return oculus->getWidthLeft(); }
EXPORT_LIB unsigned int Oculus_heightLeft(Oculus *oculus) { return oculus->getHeightLeft(); }
EXPORT_LIB unsigned int Oculus_widthRight(Oculus *oculus) { return oculus->getWidthRight(); }
EXPORT_LIB unsigned int Oculus_heightRight(Oculus *oculus) { return oculus->getHeightRight(); }
EXPORT_LIB void Oculus_projectionMatrixLeft(Oculus *oculus, float nearz, float farz, float *r_matrix) { oculus->getProjectionMatrixLeft(nearz, farz, r_matrix); }
EXPORT_LIB void Oculus_projectionMatrixRight(Oculus *oculus, const float nearz, const float farz, float *r_matrix) { oculus->getProjectionMatrixRight(nearz, farz, r_matrix); }

#undef EXPORT_LIB
#endif /* __BRIDGE_C_API_H__ */