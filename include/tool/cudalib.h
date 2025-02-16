#pragma once
#include "tool/macro.h"
#include "tool/rcman.h"

namespace tinker {
/// \ingroup platform
/// Sets up the CUDA variables including but not limited to CUDA streams, CUDA library handles,
/// and CUDA memory buffers, and integer units for the queues.
void cudalibData(RcOp);
}

//====================================================================//
//                                                                    //
//                          Global Variables                          //
//                                                                    //
//====================================================================//

#if TINKER_CUDART
#   include <cublas_v2.h>
#   include <cuda_runtime.h>

namespace tinker {
namespace g {
/// \ingroup async
/// \brief CUDA stream for the default OpenACC async queue.
TINKER_EXTERN cudaStream_t s0;
/// \ingroup async
/// \brief CUDA stream for the default OpenACC sync queue.
TINKER_EXTERN cudaStream_t s1;
/// \ingroup pme
/// \brief CUDA stream for the OpenACC async %PME queue.
TINKER_EXTERN cudaStream_t spme;
/// \ingroup async
/// \brief CUDA BLAS handle using #s0.
TINKER_EXTERN cublasHandle_t h0;
/// \ingroup async
/// \brief CUDA BLAS handle using #s1.
TINKER_EXTERN cublasHandle_t h1;
}

/// \addtogroup platform
/// \{
TINKER_EXTERN void* pinned_buf; ///< Preallocated pinned host memory.
TINKER_EXTERN void* dptr_buf;   ///< Preallocated device memory.
/// \}

/// \ingroup pme
TINKER_EXTERN cudaEvent_t pme_event_start;
/// \ingroup pme
TINKER_EXTERN cudaEvent_t pme_event_finish;
}
#endif
