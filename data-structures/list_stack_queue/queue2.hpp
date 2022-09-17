#include <algorithm>
#include <iostream>

#include "vector.hpp"

template <typename Object>
class Queue {
 public:
  explicit Queue(size_t capacity = 16)
      : front_index{0},
        back_index{-1},
        theSize{0},
        theCapacity{capacity},
        vector{capacity} {
    std::cout << "ctor" << std::endl;
  }
  ~Queue() {}
  Queue(const Queue& rhs)
      : front_index{rhs.front_index},
        back_index{rhs.back_index},
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity},
        vector{rhs.vector} {
    std::cout << "copy ctor" << std::endl;
  }
  Queue& operator=(const Queue& rhs) {
    std::cout << "copy operator" << std::endl;
    Queue copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Queue(Queue&& rhs)
      : front_index{rhs.front_index},
        back_index{rhs.back_index},
        theSize{rhs.theSize},
        theCapacity{rhs.theCapacity},
        vector{std::move(rhs.vector)} {
    std::cout << "move ctor" << std::endl;
  }

  Queue& operator=(Queue&& rhs) {
    std::cout << "move operator" << std::endl;
    std::swap(front_index, rhs.front_index);
    std::swap(back_index, rhs.back_index);
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(vector, rhs.vector);
    return *this;
  }

  Object& front() { return vector[front_index]; }
  const Object& front() const { return vector[front_index]; }
  Object& back() { return vector[back_index]; }
  const Object& back() const { return vector[back_index]; }

  void enqueue(const Object& x) {
    if (theSize == theCapacity) {
      // TODO
      //   std::cout << "full, cannot enqueue" << std::endl;
      //   return;
      reserve(2 * theCapacity + 1);
    }
    ++theSize;
    ++back_index;
    if (back_index == theCapacity) {
      back_index = 0;
      vector[back_index] = x;
    } else
      vector[back_index] = x;
  }
  void enqueue(Object&& x) {
    if (theSize == theCapacity) {
      // TODO
      //   std::cout << "full, cannot enqueue" << std::endl;
      //   return;
      reserve(2 * theCapacity + 1);
    }
    ++theSize;
    ++back_index;
    if (back_index == theCapacity) {
      back_index = 0;
      vector[back_index] = std::move(x);
    } else
      vector[back_index] = std::move(x);
  }
  void dequeue() {
    if (theSize == 0) {
      // TODO
      std::cout << "empty, cannot dequeue" << std::endl;
      return;
    }
    --theSize;
    ++front_index;
    if (front_index == theCapacity) {
      front_index = 0;
    }
  }

  bool empty() { return theSize == 0; }
  int size() { return theSize; }

  void print() const {
    if (theSize == 0) return;
    int start = front_index;
    std::cout << "size: " << theSize << std::endl;
    for (int i = 0; i < theSize; i++) {
      if (start == theCapacity) start = 0;
      std::cout << vector[start++] << " ";
    }
    std::cout << std::endl;
  }

  void reserve(size_t capacity) {
    Vector<Object> vec{capacity};
    int start = front_index;
    for (int i = 0; i < theSize; i++) {
      if (start == capacity) start = 0;
      vec[i] = vector[start++];
    }
    vector = std::move(vec);
    theCapacity = capacity;
    front_index = 0;
    if (theSize == 0)
      back_index = -1;
    else
      back_index = theSize - 1;
  }

 private:
  int front_index = 0, back_index = -1;
  size_t theSize;
  size_t theCapacity;
  Vector<Object> vector;
};