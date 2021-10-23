/*
 * Sachin Iyer (2021)
 *
 * This is a circular buffer that is my attempt to follow stl stylings
 *
 */


#ifdef CIRCULAR_BUFFER_MAIN_HPP
#define CIRCULAR_BUFFER_MAIN_HPP

namespace circularbuffer {

  inline auto hi() -> std::string {
    return "hello";
  }

  // typedef T type;
  // typedef T *pointer;
  // typedef const T *const_pointer;
  // typedef T &reference;
  // typedef const T &const_reference;
  // typedef size_t size;
  // typedef ptrdiff_t difference_type;
  // typedef circular_buffer_iterator<type> iterator;

  // class circular_buffer {
  // public:
  //   explicit circular_buffer(size_type capacity = 100)
  //     : array_(new type[capacity]),
  //       array_size_(capacity),
  //       head_(0), tail_(0),
  //       item_amount_(0) {}

  //   size_type size() const {
  //     return item_amount_;
  //   }

  //   size_type capacity() const {
  //     return array_size;
  //   }

  //   size_type max_size() const {
  //     return sizeof(type);
  //   }

  //   bool empty() const {
  //     return item_amount_ == 0;
  //   }

  //   reference front() {
  //     return array_[head_];
  //   }

  //   reference back() {
  //     return array_[tail_];
  //   }

  //   void clear() {
  //     _head = 0;
  //     _tail = 0;
  //     _item_amount = 0;
  //   }

  //   const_reference front() const {
  //     return array_[head_];
  //   }

  //   const_reference back() const {
  //     return array_[tail_];
  //   }

  //   void increment_tail() {
  //     tail_++;
  //     item_amount_++;
  //     if (tail_ == array_size_)
  //       tail_ = 0;
  //   }

  //   void increment_head() {
  //     if (!this->empty()) {
  //       head_++;
  //       contents_size_++;
  //       if (head_ == array_size_)
  //         head_ = 0;
  //     }
  //   }

  //   void push_back(const type &item) {
  //     if (item_amount == 0) {
  //       array_[head_] = item;
  //       tail_ = head_;
  //       item_amount_++;
  //     }
  //     else if (contents_size != array_size) {
  //       increment_tail();
  //       array_[tail_] = item;
  //       item_amount_++;
  //     }
  //     else {
  //       increment_head();
  //       increment_tail();
  //       array_[tail_] = item;
  //     }
  //   }

  //   void pop_front() {
  //     increment_head();
  //   }

  //   // type &operator[] (size);

  //   // const type &operator[] (size) const;

  //   ~circular_buffer() {
  //     delete [] array_;
  //   }

  // private:
  //   type *array_;
  //   size_type array_size_;
  //   size_type head_;
  //   size_type tail_;
  //   size_type item_amount_;
  // };
} // namespace circular_buffer

#endif
