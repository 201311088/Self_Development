#include "sample4.h"
#include "gtest/gtest.h"
namespace {

Counter IndependantInstance;
TEST(CounterTest, Try1) 
{
  EXPECT_EQ(0, IndependantInstance.Increment())<<"Say when it's failed"; 
  EXPECT_EQ(1, IndependantInstance.Increment())<<"Say when it's failed"; 
  EXPECT_EQ(2, IndependantInstance.Increment())<<"Say when it's failed";   
}
TEST(CounterTest, Try2) 
{
  EXPECT_EQ(3, IndependantInstance.Increment())<<"Say when it's failed";   
}
TEST(CounterTest, Try3) 
{
  EXPECT_EQ(4, IndependantInstance.Increment())<<"Say when it's failed";  
}
TEST(CounterTest, Try4) 
{
  EXPECT_EQ(5, IndependantInstance.Increment())<<"Say when it's failed";  
}
TEST(CounterTest, Try5) 
{
  EXPECT_EQ(0, IndependantInstance.Increment())<<"Say when it's failed";  
}

TEST(ConstantFailTest, Test1) 
{
  EXPECT_TRUE(false)<<"Say when it's failed";  
}

}  // namespace End


