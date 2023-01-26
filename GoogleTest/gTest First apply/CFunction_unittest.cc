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

      fulled_DB = CFunctions(98); // 2 more Insertion avaliable 

    }

    void InsertTester(const int nInput )
    {
        std::cout << "JMLEE] " << nInput << std::endl;
        //int InsertedIdx1 = empty_DB.Insert(nInput)-1;
        //int InsertedIdx2 = half_filled_DB.Insert(nInput)-1;
        int InsertedIdx3 = fulled_DB.Insert(nInput)-1;

        //std::cout << CYN" \nInsertedIdx1 = "<< InsertedIdx1 <<NC<< std::endl;
        //std::cout << CYN" \nInsertedIdx2 = "<< InsertedIdx2 <<NC<< std::endl;
        std::cout << CYN" \n Inserted At : "<< InsertedIdx3 <<NC<< std::endl;

        // EXPECT_EQ( empty_DB.getValue(InsertedIdx1)         , nInput )
        // <<"empty Start DB Failed to Insert Value: Index("<<InsertedIdx1<<")\n";
        // EXPECT_EQ( half_filled_DB.getValue(InsertedIdx2)   , nInput )
        // <<"Half Start DB Failed to Insert Value: Index("<<InsertedIdx2<<")\n";
        EXPECT_EQ( fulled_DB.getValue(InsertedIdx3)        , nInput )
        <<"Fully Start DB Failed to Insert Value: Index("<<InsertedIdx3<<")\n";
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
    //EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(INT_MAX+1) );  // DB is consist of Array<int>

    /* TEST Insert() Value Updating TEST */
    int insertValue = 512;
    
    InsertTester(insertValue); // fulled_DB(98/99)
    InsertTester(insertValue); // fulled_DB(99/99)
    InsertTester(insertValue); //! fulled_DB(100/99)  유의미한 쓰레기값 발생.
    //InsertTester(insertValue); //! fulled_DB(101/99)
    //InsertTester(insertValue); //! fulled_DB(102/99)
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
