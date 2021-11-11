#pragma once

#include <vector>
namespace circular_buffer {
  template <class T>
  class circular_buffer {
  public:
    static void default_callback(T) {}

    explicit circular_buffer(std::size_t given_capacity = 100,
			     void(* given_callback)(T) = default_callback)
      : buff(given_capacity), elements(0), head(0), tail(0), del_callback(given_callback) {
    }

    std::size_t size() const {
      return elements;
    }

    std::size_t capacity() const {
      return buff.size();
    }

    bool empty() const {
      return elements == 0;
    }

    T& front() {
      return buff[head];
    }

    T& back() {
      return buff[tail];
    }

    void clear() {
      head = 0;
      tail = 0;
      elements = 0;
    }

    const T& front() const {
      return buff[head];
    }

    const T& back() const {
      return buff[tail];
    }

    void increment_tail() {
      tail++;
      elements++;
      if (tail == buff.size())
        tail = 0;
    }

    void increment_head() {
      if (!this->empty()) {
        head++;
	elements--;
        if (head == buff.size())
          head = 0;
      }
    }

    void push_back(const T &item) {
      if (elements == 0) {
        buff[head] = item;
        tail = head;
	elements++;
      }
      else if (elements < buff.size()) {
        increment_tail();
        buff[tail] = item;
      }
      else {
	del_callback(this->front());
        increment_head();
        increment_tail();
        buff[tail] = item;
      }
    }

    void pop_front() {
      increment_head();
    }

    T& operator[](std::size_t ref) {
      if (ref < buff.size()) {
        return(buff[ref]);
      }
      throw std::out_of_range ("out of range");
    }

    const T& operator[] (std::size_t ref) const  {
      if (ref < buff.size()) {
        return(buff[ref]);
      }
      throw std::out_of_range ("out of range");
    }

    circular_buffer(const circular_buffer& o) :
      elements(o.elements),
      head(o.head), tail(o.tail), del_callback(o.del_callback){

	for (std::size_t i = 0; i < o.buff.size(); i++) {
	  buff.emplace_back(o.buff[i]);
      }
    }

    circular_buffer& operator=(const circular_buffer& o) {
      if (this != &o) {
        head = o.head;
        tail = o.tail;
        elements = o.elements;
	del_callback = o.del_callback;
	buff.clear();
	for (std::size_t i = 0; i < o.buff.size(); i++) {
	  buff.emplace_back(o.buff[i]);
	}
      }
      return *this;
    }

  private:
    std::vector<T> buff;
    std::size_t elements;
    std::size_t head;
    std::size_t tail;
    void (* del_callback)(T);
  };
}
