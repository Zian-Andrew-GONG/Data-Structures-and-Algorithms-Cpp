#pragma once
#include <algorithm>
#include <iostream>

#include "vector.hpp"

template <typename Object>
class Stack {
 public:
  Stack() : vector() { std::cout << "ctor" << std::endl; }
  ~Stack() {}
  Stack(const Stack& rhs) : vector{rhs.vector} {
    std::cout << "copy ctor" << std::endl;
  }
  Stack& operator=(const Stack& rhs) {
    std::cout << "copy operator" << std::endl;
    Stack copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Stack(Stack&& rhs) : vector{std::move(rhs.vector)} {
    std::cout << "move ctor" << std::endl;
  }
  Stack& operator=(Stack&& rhs) {
    std::cout << "move operator" << std::endl;
    std::swap(this->vector, rhs.vector);
    return *this;
  }

  void push(const Object& x) { vector.push_back(x); }
  void push(Object&& x) { vector.push_back(x); }
  void pop() { vector.pop_back(); }
  Object& top() { vector.back(); }
  const Object& top() const { vector.back(); }

 private:
  Vector<Object> vector;
};