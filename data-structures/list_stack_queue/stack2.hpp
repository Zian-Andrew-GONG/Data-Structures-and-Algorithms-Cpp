#pragma once
#include "vector.hpp"

template <typename Object>
class Stack {
 public:
  Stack() : vector() {}
  ~Stack() {}
  Stack(const Stack& rhs) : vector{rhs.vector} {}
  Stack& operator=(const Stack& rhs) {
    Stack copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Stack(Stack&& rhs) : vector{rhs.vector} {}
  Stack& operator=(Stack&& rhs) {
    std::swap(*this, rhs);
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