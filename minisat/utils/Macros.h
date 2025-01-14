/* Original Licence */
// Copyright 2010-2017 Google
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

#include <cstdlib>  // for size_t.

#if (defined(__GNUC__) || defined(__APPLE__)) && !defined(SWIG)
#define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#else  // GCC
#define ATTRIBUTE_UNUSED
#endif  // GCC

#define COMPILE_ASSERT(x, msg)

#ifdef NDEBUG
const bool DEBUG_MODE = false;
#else   // NDEBUG
const bool DEBUG_MODE = true;
#endif  // NDEBUG

// DISALLOW_COPY_AND_ASSIGN disallows the copy and operator= functions.
// It goes in the private: declarations in a class.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

// The FALLTHROUGH_INTENDED macro can be used to annotate implicit fall-through
// between switch labels.
#ifndef FALLTHROUGH_INTENDED
#define FALLTHROUGH_INTENDED \
  do {                       \
  } while (0)
#endif
