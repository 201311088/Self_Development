#include "CFunctions.h"
#include "gtest/gtest.h"
#define CYN "\e[0;36m"
#define NC "\e[0m"

namespace {

int test_sharing_idx=0;

class FunctionTesting : public testing::Test   
{
protected:  
    void SetUp() override   
    {
        empty_DB = CFunctions(0);
half_filled_DB = CFunctions(49);
fulled_DB = CFunctions(100);
    }

    void InsertTester(const int nInput )
    {

        int TestingIdx1 = empty_DB.         Insert(nInput)-1;
        int TestingIdx2 = half_filled_DB.   Insert(nInput)-1;
        int TestingIdx3 = fulled_DB.        Insert(nInput)-1;

        std::cout << CYN" \nTestingIdx1 = "<< TestingIdx1 <<NC<< std::endl;
        std::cout << CYN" \nTestingIdx2 = "<< TestingIdx2 <<NC<< std::endl;
        std::cout << CYN" \nTestingIdx3 = "<< TestingIdx3 <<NC<< std::endl;

        EXPECT_EQ( empty_DB.getValue(TestingIdx1)         , nInput )
        <<"empty Start DB Failed to Insert Value: Index("<<TestingIdx1<<")\n";
        EXPECT_EQ( half_filled_DB.getValue(TestingIdx2)   , nInput )
        <<"Half Start DB Failed to Insert Value: Index("<<TestingIdx2<<")\n";
        EXPECT_EQ( fulled_DB.getValue(TestingIdx3)        , nInput )
        <<"Fully Start DB Failed to Insert Value: Index("<<TestingIdx3<<")\n";
    }

    void TearDown() override   
    {}
    
    CFunctions empty_DB;
    CFunctions half_filled_DB;
    CFunctions fulled_DB;
};

#define INT_MAX 2147483647

TEST_F(FunctionTesting, Testing_Insert) { 
    /* TEST Insert() return value */
    //EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(1000) ); 
    //EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(3.141592) ); 
   // EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(INT_MAX+1) );  // DB is consist of Array<int>

    /* TEST Insert() Value Updating TEST */
    InsertTester(51);
        InsertTester(75);

}


/*
TEST_F(FunctionTesting, Testing_Delete) {

}

TEST_F(FunctionTesting, Testing_Update) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}

TEST_F(FunctionTesting, Testing_Search) {
  MapTester(&q0_);
  MapTester(&q1_);
  MapTester(&q2_);
}
*/

}  // namespace
