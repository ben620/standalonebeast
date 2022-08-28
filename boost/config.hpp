#pragma once
#include <cassert>
#define BOOST_NO_ALIGNMENT
#define BOOST_IF_CONSTEXPR if constexpr

#define BOOST_THROW_EXCEPTION throw
#ifndef BOOST_ASSERT
# define BOOST_ASSERT(expr) assert(expr)
#endif
#ifndef BOOST_ASSERT_MSG
# define BOOST_ASSERT_MSG(expr, msg) assert((expr)&&(msg))
#endif

#define BOOST_STATIC_CONSTANT(t, v) static const t v
#define BOOST_VERIFY assert
#define BOOST_BEAST_USE_STD_STRING_VIEW 1
#define BOOST_INTRUSIVE_SAFE_HOOK_DEFAULT_ASSERT BOOST_ASSERT

#define BOOST_INTRUSIVE_INVARIANT_ASSERT BOOST_ASSERT

#define BOOST_CONSTEXPR constexpr

#define BOOST_STATIC_ASSERT_MSG static_assert

#ifdef _WIN32
#define BOOST_LIKELY(x) x
#define BOOST_UNLIKELY(x) x
#else
#define BOOST_LIKELY(x) __builtin_expect(x, 1)
#define BOOST_UNLIKELY(x) __builtin_expect(x, 0)
#endif

#if !defined(BOOST_ALIGNMENT)
#  if !defined(BOOST_NO_CXX11_ALIGNAS)
#    define BOOST_ALIGNMENT(x) alignas(x)
#  elif defined(_MSC_VER)
#    define BOOST_ALIGNMENT(x) __declspec(align(x))
#  elif defined(__GNUC__)
#    define BOOST_ALIGNMENT(x) __attribute__ ((__aligned__(x)))
#  else
#    define BOOST_NO_ALIGNMENT
#    define BOOST_ALIGNMENT(x)
#  endif
#endif