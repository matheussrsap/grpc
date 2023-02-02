// Copyright 2022 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Automatically generated by tools/codegen/core/gen_experiments.py
//
// This file contains the autogenerated parts of the experiments API.
//
// It generates two symbols for each experiment.
//
// For the experiment named new_car_project, it generates:
//
// - a function IsNewCarProjectEnabled() that returns true if the experiment
//   should be enabled at runtime.
//
// - a macro GRPC_EXPERIMENT_IS_INCLUDED_NEW_CAR_PROJECT that is defined if the
//   experiment *could* be enabled at runtime.
//
// The function is used to determine whether to run the experiment or
// non-experiment code path.
//
// If the experiment brings significant bloat, the macro can be used to avoid
// including the experiment code path in the binary for binaries that are size
// sensitive.
//
// By default that includes our iOS and Android builds.
//
// Finally, a small array is included that contains the metadata for each
// experiment.
//
// A macro, GRPC_EXPERIMENTS_ARE_FINAL, controls whether we fix experiment
// configuration at build time (if it's defined) or allow it to be tuned at
// runtime (if it's disabled).
//
// If you are using the Bazel build system, that macro can be configured with
// --define=grpc_experiments_are_final=true

#ifndef GRPC_SRC_CORE_LIB_EXPERIMENTS_EXPERIMENTS_H
#define GRPC_SRC_CORE_LIB_EXPERIMENTS_EXPERIMENTS_H

#include <grpc/support/port_platform.h>

#include <stddef.h>

#include "src/core/lib/experiments/config.h"

namespace grpc_core {

#ifdef GRPC_EXPERIMENTS_ARE_FINAL
inline bool IsTcpFrameSizeTuningEnabled() { return false; }
inline bool IsTcpRcvLowatEnabled() { return false; }
inline bool IsPeerStateBasedFramingEnabled() { return false; }
#define GRPC_EXPERIMENT_IS_INCLUDED_FLOW_CONTROL_FIXES
inline bool IsFlowControlFixesEnabled() { return true; }
inline bool IsMemoryPressureControllerEnabled() { return false; }
inline bool IsUnconstrainedMaxQuotaBufferSizeEnabled() { return false; }
#define GRPC_EXPERIMENT_IS_INCLUDED_NEW_HPACK_HUFFMAN_DECODER
inline bool IsNewHpackHuffmanDecoderEnabled() { return true; }
inline bool IsEventEngineClientEnabled() { return false; }
#define GRPC_EXPERIMENT_IS_INCLUDED_MONITORING_EXPERIMENT
inline bool IsMonitoringExperimentEnabled() { return true; }
inline bool IsPromiseBasedClientCallEnabled() { return false; }
inline bool IsFreeLargeAllocatorEnabled() { return false; }
inline bool IsPromiseBasedServerCallEnabled() { return false; }
inline bool IsTransportSuppliesClientLatencyEnabled() { return false; }
inline bool IsEventEngineListenerEnabled() { return false; }
#else
#define GRPC_EXPERIMENT_IS_INCLUDED_TCP_FRAME_SIZE_TUNING
inline bool IsTcpFrameSizeTuningEnabled() { return IsExperimentEnabled(0); }
#define GRPC_EXPERIMENT_IS_INCLUDED_TCP_RCV_LOWAT
inline bool IsTcpRcvLowatEnabled() { return IsExperimentEnabled(1); }
#define GRPC_EXPERIMENT_IS_INCLUDED_PEER_STATE_BASED_FRAMING
inline bool IsPeerStateBasedFramingEnabled() { return IsExperimentEnabled(2); }
#define GRPC_EXPERIMENT_IS_INCLUDED_FLOW_CONTROL_FIXES
inline bool IsFlowControlFixesEnabled() { return IsExperimentEnabled(3); }
#define GRPC_EXPERIMENT_IS_INCLUDED_MEMORY_PRESSURE_CONTROLLER
inline bool IsMemoryPressureControllerEnabled() {
  return IsExperimentEnabled(4);
}
#define GRPC_EXPERIMENT_IS_INCLUDED_UNCONSTRAINED_MAX_QUOTA_BUFFER_SIZE
inline bool IsUnconstrainedMaxQuotaBufferSizeEnabled() {
  return IsExperimentEnabled(5);
}
#define GRPC_EXPERIMENT_IS_INCLUDED_NEW_HPACK_HUFFMAN_DECODER
inline bool IsNewHpackHuffmanDecoderEnabled() { return IsExperimentEnabled(6); }
#define GRPC_EXPERIMENT_IS_INCLUDED_EVENT_ENGINE_CLIENT
inline bool IsEventEngineClientEnabled() { return IsExperimentEnabled(7); }
#define GRPC_EXPERIMENT_IS_INCLUDED_MONITORING_EXPERIMENT
inline bool IsMonitoringExperimentEnabled() { return IsExperimentEnabled(8); }
#define GRPC_EXPERIMENT_IS_INCLUDED_PROMISE_BASED_CLIENT_CALL
inline bool IsPromiseBasedClientCallEnabled() { return IsExperimentEnabled(9); }
#define GRPC_EXPERIMENT_IS_INCLUDED_FREE_LARGE_ALLOCATOR
inline bool IsFreeLargeAllocatorEnabled() { return IsExperimentEnabled(10); }
#define GRPC_EXPERIMENT_IS_INCLUDED_PROMISE_BASED_SERVER_CALL
inline bool IsPromiseBasedServerCallEnabled() {
  return IsExperimentEnabled(11);
}
#define GRPC_EXPERIMENT_IS_INCLUDED_TRANSPORT_SUPPLIES_CLIENT_LATENCY
inline bool IsTransportSuppliesClientLatencyEnabled() {
  return IsExperimentEnabled(12);
}
#define GRPC_EXPERIMENT_IS_INCLUDED_EVENT_ENGINE_LISTENER
inline bool IsEventEngineListenerEnabled() { return IsExperimentEnabled(13); }

constexpr const size_t kNumExperiments = 14;
extern const ExperimentMetadata g_experiment_metadata[kNumExperiments];

#endif
}  // namespace grpc_core

#endif  // GRPC_SRC_CORE_LIB_EXPERIMENTS_EXPERIMENTS_H
