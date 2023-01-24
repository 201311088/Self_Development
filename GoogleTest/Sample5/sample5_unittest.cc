#include <limits.h>
#include <time.h>
#include "sample1.h"
#include "sample3-inl.h"
#include "gtest/gtest.h"
namespace {

class QuickTest : public testing::Test {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  // This is a good place to record the start time.
  void SetUp() override 
  { 
    start_time_ = clock();; //! TEST init 직전 Setup 호출됨 ---> 시간기록 적합
    std::cout<< "START TIME >>>>>> "<< start_time_ << std::endl;
    }  

  // TearDown() is invoked immediately after a test finishes.  Here we
  // check if the test was too slow.
  void TearDown() override 
  {
    // Gets the time when the test finishes
    const clock_t end_time = clock();;
    std::cout<< "END TIME >>>>>> "<< end_time << std::endl;
    std::cout<< "TEST RUNNING TIME  :  "<< (end_time - start_time_) << " MILLISECONDS_" << std::endl;
    // Asserts that the test took no more than ~5 seconds.  Did you
    // know that you can use assertions in SetUp() and TearDown() as
    // well?
    EXPECT_TRUE(end_time - start_time_ <= 10 ) << "The test took too long.";  //! (종료-시작)시간 == TEST수행 시간 100ms 이하인지 확인.
  }

  // The UTC time (in seconds) when the test starts
  clock_t start_time_;
};


class IntegerFunctionTest : public QuickTest {

};

// Now we can write tests in the IntegerFunctionTest test case.

// Tests Factorial()
TEST_F(IntegerFunctionTest, Factorial) 
{
  // Tests factorial of negative numbers.
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);

  // Tests factorial of 0.
  EXPECT_EQ(1, Factorial(0));

  // Tests factorial of positive numbers.
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8522152));
}

// Tests IsPrime()
TEST_F(IntegerFunctionTest, IsPrime) {
  // Tests negative input.
  EXPECT_FALSE(IsPrime(-1));
  EXPECT_FALSE(IsPrime(-2));
  EXPECT_FALSE(IsPrime(INT_MIN));

  // Tests some trivial cases.
  EXPECT_FALSE(IsPrime(0));
  EXPECT_FALSE(IsPrime(1));
  EXPECT_TRUE(IsPrime(2));
  EXPECT_TRUE(IsPrime(3));

  // Tests positive input.
  EXPECT_FALSE(IsPrime(4));
  EXPECT_TRUE(IsPrime(5));
  EXPECT_FALSE(IsPrime(6));
  EXPECT_TRUE(IsPrime(23));
}

// The next test case (named "QueueTest") also needs to be quick, so
// we derive another fixture from QuickTest.
//
// The QueueTest test fixture has some logic and shared objects in
// addition to what's in QuickTest already.  We define the additional
// stuff inside the body of the test fixture, as usual.
class QueueTest : public QuickTest {
 protected:
  void SetUp() override {
    // First, we need to set up the super fixture (QuickTest).
    QuickTest::SetUp();

    // Second, some additional setup for this fixture.
    q1_.Enqueue(1);
    q2_.Enqueue(2);
    q2_.Enqueue(3);
  }
  // By default, TearDown() inherits the behavior of
  // QuickTest::TearDown().  As we have no additional cleaning work
  // for QueueTest, we omit it here.
  //
  // virtual void TearDown() {
  //   QuickTest::TearDown();
  // }

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

// Now, let's write tests using the QueueTest fixture.

// Tests the default constructor.
TEST_F(QueueTest, DefaultConstructor) { EXPECT_EQ(0u, q0_.Size()); }

// Tests Dequeue().
TEST_F(QueueTest, Dequeue) 
{
  int* n = q0_.Dequeue();
  EXPECT_TRUE(n == nullptr);

  n = q1_.Dequeue();
  EXPECT_TRUE(n != nullptr);
  EXPECT_EQ(1, *n);
  EXPECT_EQ(0u, q1_.Size());
  delete n;

  n = q2_.Dequeue();
  EXPECT_TRUE(n != nullptr);
  EXPECT_EQ(2, *n);
  EXPECT_EQ(1u, q2_.Size());
  delete n;
}
}  // namespace
// If necessary, you can derive further test fixtures from a derived
// fixture itself.  For example, you can derive another fixture from
// QueueTest.  Google Test imposes no limit on how deep the hierarchy
// can be.  In practice, however, you probably don't want it to be too
// deep as to be confusing.
