#pragma once

#include <string>
namespace circular_buffer {
  inline auto hi() -> std::string {
    return "hello";
  }

  template <class T>
  class circular_buffer {
  public:
    explicit circular_buffer(size_t capacity = 100)
      : array_(new T[capacity]),
        array_size_(capacity),
        head_(0), tail_(0),
        item_amount_(0) {}

    size_t size() const {
      return item_amount_;
    }

    size_t capacity() const {
      return array_size_;
    }

    size_t max_size() const {
      return sizeof(T);
    }

    bool empty() const {
      return item_amount_ == 0;
    }

    T& front() {
      return array_[head_];
    }

    T& back() {
      return array_[tail_];
    }

    void clear() {
      head_ = 0;
      tail_ = 0;
      item_amount_ = 0;
    }

    const T& front() const {
      return array_[head_];
    }

    const T& back() const {
      return array_[tail_];
    }

    void increment_tail() {
      tail_++;
      item_amount_++;
      if (tail_ == array_size_)
        tail_ = 0;
    }

    void increment_head() {
      if (!this->empty()) {
        head_++;
        item_amount_--;
        if (head_ == array_size_)
          head_ = 0;
      }
    }

    void push_back(const T &item) {
      if (item_amount_ == 0) {
        array_[head_] = item;
        tail_ = head_;
        item_amount_++;
      }
      else if (item_amount_ < array_size_) {
        increment_tail();
        array_[tail_] = item;
      }
      else {
        increment_head();
        increment_tail();
        array_[tail_] = item;
      }
    }

    void pop_front() {
      increment_head();
    }

    T& operator[](size_t ref) {
      if (ref <= item_amount_) {
        return(array_[ref]);
      }
      throw std::out_of_range ("out of range");
    }

    T operator[] (size_t ref) const  {
      if (ref <= item_amount_) {
        return(array_[ref]);
      }
      throw std::out_of_range ("out of range");
    }

    ~circular_buffer() {
      delete [] array_;
    }

    circular_buffer(const circular_buffer& o) {
      array_size_ = o.array_size_;
      head_ = o.head_;
      tail_ = o.tail_;
      item_amount_ = o.item_amount_;
      for (size_t i = 0; i < array_size_; i++) {
        array_[i] = o.array_[i];
      }
    }

    circular_buffer& operator=(const circular_buffer& o) {
      if (this != o) {
        delete [] array_;
        array_size_ = o.array_size_;
        head_ = o.head_;
        tail_ = o.tail_;
        item_amount_ = o.item_amount_;
        array_ = new T(array_size_);
	for (size_t i = 0; i < array_size_; i++) {
	  array_[i] = o.array_[i];
	}
      }
    }

  private:
    T* array_;
    size_t array_size_;
    size_t head_;
    size_t tail_;
    size_t item_amount_;
  };


}
