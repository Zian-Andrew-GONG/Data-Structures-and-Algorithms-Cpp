#pragma once
#include <algorithm>
#include <iostream>

#include "list.hpp"

template <typename Object>
class Stack {
 public:
  Stack() : list() { std::cout << "ctor" << std::endl; }
  ~Stack() {}
  Stack(const Stack& rhs) {
    std::cout << "copy ctor" << std::endl;
    list = rhs.list;
  }
  Stack& operator=(const Stack& rhs) {
    std::cout << "copy operator" << std::endl;
    Stack copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Stack(Stack&& rhs) : list{rhs.list} { std::cout << "move ctor" << std::endl; }
  Stack& operator=(Stack&& rhs) {
    std::cout << "move operator" << std::endl;
    std::swap(list, rhs.list);
    return *this;
  }

  void push(const Object& x) { list.push_back(x); }
  void push(Object&& x) { list.push_back(x); }
  void pop() { list.pop_back(); }
  Object& top() { list.back(); }
  const Object& top() const { list.back(); }

 private:
  List<Object> list;
};