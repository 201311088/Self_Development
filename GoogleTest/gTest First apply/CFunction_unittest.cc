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
        empty_DB = CFunctions(0);         // Test Instance1
        half_filled_DB = CFunctions(49);  // Test Instance2
        fulled_DB = CFunctions(100);      // Test Instance3
    }

    void InsertTester(const int nInput )
    {

        int InsertedIdx1 = empty_DB.Insert(nInput)-1;
        int InsertedIdx2 = half_filled_DB.Insert(nInput)-1;
        int InsertedIdx3 = fulled_DB.Insert(nInput)-1; 

        std::cout << CYN" \n InsertedIdx1 = "<< InsertedIdx1 <<NC;
        std::cout << CYN" \n InsertedIdx2 = "<< InsertedIdx2 <<NC;
        std::cout << CYN" \n InsertedIdx3 = "<< InsertedIdx3 <<NC<< std::endl;

        EXPECT_EQ( empty_DB.getValue(InsertedIdx1)         , nInput )
        <<"empty Start DB Failed to Insert Value: Index("<<InsertedIdx1<<")\n";
        EXPECT_EQ( half_filled_DB.getValue(InsertedIdx2)   , nInput )
        <<"Half Start DB Failed to Insert Value: Index("<<InsertedIdx2<<")\n";
        EXPECT_EQ( fulled_DB.getValue(InsertedIdx3)        , -1     )   // Should be same with Initialized Value(-1).
        <<"Fully Start DB Failed to Insert Value: Index("<<InsertedIdx3<<")\n";
    }

    void DeleteTester()
    {
      for(int i=0; i<STATIC_MAX; i++) // Try Delete() in ALL Usable Static Range.
      {
          half_filled_DB.Delete( i );
          EXPECT_EQ(-1, half_filled_DB.getValue(i) );
      }
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
    EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(1000) ); 
    EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(3.141592) ); 
    EXPECT_EQ( half_filled_DB.getIndex() , half_filled_DB.Insert(INT_MAX+1) );  // DB is consist of INT array

    /* TEST Insert() Value Updating TEST */
    int insertValue = 1234;
    InsertTester(insertValue);
    InsertTester(insertValue);
    InsertTester(insertValue);
    InsertTester(insertValue);

}

TEST_F(FunctionTesting,Update_and_getValue_test) {
  int nIndex = 75;  
  int nValue = 1;   // All Indexes have -1 value initially.
  half_filled_DB.Update( nIndex, nValue );
  EXPECT_EQ( nValue, half_filled_DB.getValue(nIndex));
}

TEST_F(FunctionTesting, Delete_test) {
  DeleteTester();
}

}  // namespace
