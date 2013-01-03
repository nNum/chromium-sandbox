// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SANDBOX_LINUX_SERVICES_ANDROID_ARM_UCONTEXT_H_
#define SANDBOX_LINUX_SERVICES_ANDROID_ARM_UCONTEXT_H_

#include <asm/sigcontext.h>

typedef long int greg_t;
typedef unsigned long sigset_t;
typedef struct ucontext {
  unsigned long   uc_flags;
  struct ucontext  *uc_link;
  stack_t     uc_stack;
  struct sigcontext uc_mcontext;
  sigset_t    uc_sigmask;
  /* Allow for uc_sigmask growth.  Glibc uses a 1024-bit sigset_t.  */
  int     __not_used[32 - (sizeof (sigset_t) / sizeof (int))];
  /* Last for extensibility.  Eight byte aligned because some
     coprocessors require eight byte alignment.  */
  unsigned long   uc_regspace[128] __attribute__((__aligned__(8)));
} ucontext_t;
#endif  // SANDBOX_LINUX_SERVICES_ANDROID_ARM_UCONTEXT_H_