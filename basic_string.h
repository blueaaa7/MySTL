#ifndef MYTINYSTL_BASIC_STRING_H_
#define MYTINYSTL_BASIC_STRING_H_

// 这个头文件包含一个模板类basic_string 用于表示字符串类型
#include <iostream>

#include "iterator.h"
#include "memory.h"
#include "functional.h"
#include "exceptdef.h"

namespace mystl
{
  // char traits
  template <class CharType>
  struct char_traits
  {
    typedef CharType char_type;

    static size_t length(const char_type *str)
    {
      size_t len = 0;
      for (; *str != char_type(0); ++str)
        ++len;
      return len;
    }
  

  static int compare(const char_type* s1, const char_type* s2, size_t n)
  {
    for (; n != 0; --n, ++s1, ++s2)
    {
      if (*s1 < *s2)
        return -1;
      if (*s2 < *s1)
        return 1;
    }
    return 0;
  }

  static char_type* copy(char_type* dst, const char_type* src, size_t n)
  {
    MYSTL_DEBUG(src + n <= dst || dst + n <= src);
    char_type* r = dst;
    for (; n != 0; --n, ++dst, ++src)
      *dst = *src;
    return r;
  }


  static char_type* move(char_type* dst, const char_type* src, size_t n)
  {
    char_type* r = dst;
    if (dst < src)
    {
      for (; n != 0; --n, ++dst, ++src)
        *dst = *src;
    }
    else if (src < dst)
    {
      dst += n;
      src += n;
      for (; n != 0; --n)
        *--dst = *--src;
    }
    return r;
  }


  
  
  
  
  };
  

}
#endif