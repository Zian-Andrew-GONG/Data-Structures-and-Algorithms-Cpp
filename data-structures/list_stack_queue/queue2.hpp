#pragma once
#include "vector.hpp"

template <typename Object>
class Queue {
 public:
  explicit Queue(int size = 16) : theSize{size}, front_index{0}, back_index{0} {
    reserve(size);
  }
  ~Queue() {}
  Queue(const Queue& rhs) {}
  Queue& operator=(const Queue& rhs) {}
  Queue(Queue&& rhs) {}
  Queue& operator=(Queue&& rhs) {}


  Object& front() { return vector[front_index]; }
  Object& front() const { return vector[front_index]; }
  Object& back() { return vector[back_index]; }
  Object& back() const { return vector[back_index]; }

  void enqueue(const Object& x) {
    if (++theSize > vector.capacity()) {
      reserve(2 * theSize + 1);
    }
    if (front_index == back_index) {
      vector[back_index] = x;
    } else {
      vector[(++back_index) % theSize] = x;
    }
  }
  void enqueue(Object&& x) {}
  void dequeue() {
    if (theSize == 0) return;
    front_index = (++front_index) % theSize;
  }
  int size() { return theSize; }

 private:
  void reserve(int size) {
    Vector<Object> tmp(size);
    if (front_index < back_index) {
      for (int i = 0; i < theSize; i++) {
        tmp[i] = vector[front_index++];
      }
    } else {
      int i = 0;
      for (; front_index < theSize;) {
        tmp[i++] = vector[front_index++];
      }
      for (int j = 0; j <= back_index; j++) {
        tmp[j++] = vector[i++];
      }
    }
    front_index = 0;
    back_index = theSize - 1;
    std::swap(vector, tmp);
  }

  int theSize;
  int front_index, back_index;
  // int theCapacity;
  Vector<Object> vector;
};