#pragma once
#include "vector.hpp"

template <typename Object>
class Queue {
 public:
  explicit Queue(int capacity = SPARE_CAPACITY)
      : theCapacity{capacity}, theSize{0}, front_index{0}, back_index{0} {
    reserve(theCapacity);
  }
  ~Queue() {}
  Queue(const Queue& rhs)
      : theCapacity{rhs.theCapacity},
        theSize{rhs.theSize},
        front_index{rhs.front_index},
        back_index{rhs.back_index},
        vector{rhs.vector} {}
  Queue& operator=(const Queue& rhs) {
    Queue copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Queue(Queue&& rhs)
      : theCapacity{rhs.theCapacity},
        theSize{rhs.theSize},
        front_index{rhs.front_index},
        back_index{rhs.back_index},
        vector{rhs.vector} {}

  Queue& operator=(Queue&& rhs) {
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(theSize, rhs.theSize);
    std::swap(front_index, rhs.front_index);
    std::swap(back_index, rhs.back_index);
    std::swap(vector, rhs.vector);
    return *this;
  }

  Object& front() { return vector[front_index]; }
  const Object& front() const { return vector[front_index]; }
  Object& back() { return vector[back_index]; }
  const Object& back() const { return vector[back_index]; }

  void enqueue(const Object& x) {
    if (++theSize > theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    if (front_index == back_index) {
      vector[back_index] = x;
    } else {
      vector[(++back_index) % theSize] = x;
    }
  }
  void enqueue(Object&& x) {
    if (++theSize > theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    if (front_index == back_index) {
      vector[back_index] = x;
    } else {
      vector[(++back_index) % theSize] = x;
    }
  }
  void dequeue() {
    if (theSize-- == 0) return;
    front_index = (++front_index) % theSize;
  }
  int size() { return theSize; }
  int capacity() { return theCapacity; }
  static const int SPARE_CAPACITY = 16;

 private:
  void reserve(int capacity) {
    Vector<Object> tmp(capacity);
    if (front_index < back_index) {
      for (int i = 0; i < theCapacity; i++) {
        tmp[i] = vector[front_index++];
      }
    } else {
      int i = 0;
      for (; front_index < theCapacity;) {
        tmp[i++] = vector[front_index++];
      }
      for (int j = 0; j <= back_index; j++) {
        tmp[j++] = vector[i++];
      }
    }
    front_index = 0;
    back_index = theSize - 1;
    theCapacity = capacity;
    std::swap(vector, tmp);
  }

  int theSize;
  int theCapacity;
  int front_index, back_index;
  // int theCapacity;
  Vector<Object> vector;
};