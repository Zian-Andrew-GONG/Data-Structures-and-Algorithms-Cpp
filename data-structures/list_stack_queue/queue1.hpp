#pragma once
#include <algorithm>
#include <iostream>

#include "list.hpp"

template <typename Object>
class Queue {
 public:
  Queue() : list{} { std::cout << "ctor" << std::endl; }
  ~Queue() = default;
  Queue(const Queue& rhs) : list{rhs.list} {
    std::cout << "copy ctor" << std::endl;
  }
  Queue& operator=(const Queue& rhs) {
    std::cout << "copy operator" << std::endl;
    Queue copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Queue(Queue&& rhs) : list{std::move(rhs.list)} {
    std::cout << "move ctor" << std::endl;
  }
  Queue& operator=(Queue&& rhs) {
    std::cout << "move operator" << std::endl;
    std::swap(this->list, rhs.list);
    return *this;
  }

  Object& front() { return list.front(); }
  const Object& front() const { return list.front(); }
  Object& back() { return list.back(); }
  const Object& back() const { return list.back(); }

  void enqueue(const Object& x) { list.push_back(x); }
  void enqueue(Object&& x) { list.push_back(std::move(x)); }
  void dequeue() { list.pop_front(); }

  bool empty() { return list.empty(); }
  int size() { return list.size(); }

 private:
  List<Object> list;
};