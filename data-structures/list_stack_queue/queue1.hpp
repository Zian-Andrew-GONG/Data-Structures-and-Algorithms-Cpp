#pragma once
#include "list.hpp"

template <typename Object>
class Queue {
 public:
  Queue() : list() {}
  ~Queue() {}
  Queue(const Queue& rhs) : list{rhs.list} {}
  Queue& operator=(const Queue& rhs) {
    Queue copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Queue(Queue&& rhs) : list{rhs.list} {}
  Queue& operator=(Queue&& rhs) {
    std::swap(*this, rhs);
    return *this;
  }

  Object& front() { return list.front(); }
  const Object& front() const { return list.front(); }
  Object& back() { return list.back(); }
  const Object& back() const { return list.back(); }

  void enqueue(const Object& x) { list.push_back(x); }
  void enqueue(Object&& x) { list.push_back(x); }
  void dequeue() { list.pop_front(); }

  bool empty() { return list.empty(); }
  int size() { return list.size(); }

 private:
  List<Object> list;
};