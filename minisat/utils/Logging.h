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

#include <cassert>
#include <cstdlib>
#include <iostream>

#define INFO "INFO"
#define DEBUG_L "DEBUG"
#define WARNING "WARNING"

#define DCHECK_GE(value, cond) (assert((value) >= (cond)))
#define DCHECK_LE(value, cond) (assert((value) <= (cond)))
#define DCHECK_GT(value, cond) (assert((value) >  (cond)))
#define DCHECK_LT(value, cond) (assert((value) <  (cond)))
#define DCHECK_NE(value, cond) (assert((value) != (cond)))
#define DCHECK_EQ(value, cond) (assert((value) == (cond)))
#define DCHECK(cond) (assert((cond)))
#define DCHECK_NOTNULL(cond) (assert((cond != nullptr)))

#define CHECK_GE(value, cond) (assert((value) >= (cond)))
#define CHECK_LE(value, cond) (assert((value) <= (cond)))
#define CHECK_GT(value, cond) (assert((value) >  (cond)))
#define CHECK_LT(value, cond) (assert((value) <  (cond)))
#define CHECK_NE(value, cond) (assert((value) !=  (cond)))
#define CHECK_EQ(value, cond) (assert((value) == (cond)))
#define CHECK(cond) (assert((cond)))
#define CHECK_NOTNULL(cond) (assert((cond != nullptr)))

struct X {
    ~X() { std::cerr << std::endl; }
};

#define LOG(mode) (X(), std::cerr << "[" << mode << "]"  << ":" )

#include "minisat/utils/Macros.h"
