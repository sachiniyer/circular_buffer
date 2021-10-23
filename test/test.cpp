// test/test.cpp
#include <iostream>
#include <circular_buffer.hpp>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE("test1") {
    std::string value = circular_buffer::hi();
    REQUIRE(value == std::string("hello"));
}

TEST_CASE("test2") {
  int testnum = 20;
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(testnum);
  REQUIRE(testnum == testbuffer.front());
}

TEST_CASE("test3") {
  circular_buffer::circular_buffer<int> testbuffer;
  for (int i = 0; i < 20; i++) {
    testbuffer.push_back(i);
  }
  bool correct = true;
  for (int i = 0; i < 20; i++) {
    correct = i == testbuffer.front();
    testbuffer.pop_front();
  }
  REQUIRE(correct);
}

TEST_CASE("test4") {
  circular_buffer::circular_buffer<int> testbuffer(50);
  REQUIRE(testbuffer.capacity() == 50);
}

TEST_CASE("test5") {
  circular_buffer::circular_buffer<int> testbuffer;
  for (int i = 0; i < 10; i++) {
    testbuffer.push_back(i);
  }
  REQUIRE(testbuffer.size() == 10);
}

TEST_CASE("test6") {
  circular_buffer::circular_buffer<int> testbuffer(10);
  for (int i = 0; i < 11; i++) {
    testbuffer.push_back(i);
  }
  bool correct = true;
  for (int i = 1; i < 11; i++) {
    correct = i == testbuffer.front();
    testbuffer.pop_front();
  }
  REQUIRE(correct);
}

TEST_CASE("test7") {
  int testnum = 20;
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(testnum);
  REQUIRE(testnum == testbuffer.back());
}

TEST_CASE("test8") {
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(10);
  testbuffer.pop_front();
  REQUIRE(testbuffer.empty());
}

TEST_CASE("test9") {
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(10);
  REQUIRE(testbuffer[0] == 10);
}

TEST_CASE("test10") {
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(10);
  circular_buffer::circular_buffer<int> testbuffer2(50);
  testbuffer2 = testbuffer;
  REQUIRE(testbuffer2.front() == 10);
}

TEST_CASE("test11") {
  circular_buffer::circular_buffer<int> testbuffer;
  testbuffer.push_back(10);
  circular_buffer::circular_buffer<int> testbuffer2(testbuffer);
  REQUIRE(testbuffer2.front() == 10);
}

TEST_CASE("test12") {
  circular_buffer::circular_buffer<int>* testbuffer
    = new circular_buffer::circular_buffer<int>(20);
  REQUIRE(true);
}
