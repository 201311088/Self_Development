
#ifndef GOOGLETEST_SAMPLES_SAMPLE4_H_
#define GOOGLETEST_SAMPLES_SAMPLE4_H_

// A simple monotonic counter.
class Counter {
 private:
  int counter_;

 public:
  // Creates a counter that starts at 0.
  Counter() : counter_(0) {}

  // Returns the current counter value, and increments it.
  int Increment();

  // Returns the current counter value, and decrements it.
  int Decrement();

  // Prints the current counter value to STDOUT.
  void Print() const;
};

#endif  // GOOGLETEST_SAMPLES_SAMPLE4_H_
