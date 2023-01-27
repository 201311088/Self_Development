#include "CFunctions.h"
#include "gtest/gtest.h"
#include "time.h"
#define CYN "\e[0;36m"
#define NC "\e[0m"

namespace {


class FunctionTesting : public testing::Test   
{
protected:  
    void SetUp() override   
    {
        test_start_time = clock();
        empty_DB = CFunctions(0);         // Test Instance1
        half_filled_DB = CFunctions(49);  // Test Instance2
        fulled_DB = CFunctions(100);      // Test Instance3
    }

    void InsertTester(const int nInput )
    {
        int emtpyDB_index = empty_DB.Insert(nInput)-1;
        int halfFiiledDB_index = half_filled_DB.Insert(nInput)-1;
        int fulledDB_index = fulled_DB.Insert(nInput)-1; 

        std::cout << CYN" \n emtpyDB_index = "<< emtpyDB_index <<NC;  // COLOR PRINT = Additional custom LOG.
        std::cout << CYN"        halfFiiledDB_index = "<< halfFiiledDB_index <<NC;
        std::cout << CYN"        fulledDB_index = "<< fulledDB_index <<NC;

        EXPECT_EQ( empty_DB.getValue(emtpyDB_index)         , nInput )
        <<"empty Start DB Failed to Insert Value: Index("<<emtpyDB_index<<")\n";
        EXPECT_EQ( half_filled_DB.getValue(halfFiiledDB_index)   , nInput )
        <<"Half Start DB Failed to Insert Value: Index("<<halfFiiledDB_index<<")\n";
        EXPECT_EQ( fulled_DB.getValue(fulledDB_index)        , -1     )   // Should be same with Initialized Value(-1).
        <<"Fully Start DB Failed to Insert Value: Index("<<fulledDB_index<<")\n";
    }

    void DeleteTester()
    {
      /* Try Delete() in ALL Usable Static Range. */
      for(int i=0; i<STATIC_MAX; i++)
      {
          half_filled_DB.Delete( i );
          EXPECT_EQ(-1, half_filled_DB.getValue(i) );
      }

      /* Try Delete() in invalid Range */
      half_filled_DB.Delete(100);  // Range +1
      half_filled_DB.Delete(-34);  // Minus Range
    }

    void TearDown() override   
    {
      const clock_t test_end_time = clock();
      std::cout<< CYN" ㄴTEST RUNNING TIME  :  "<< (test_end_time - test_start_time) << " ms." <<NC<< std::endl;
    }
    
    clock_t test_start_time;
    CFunctions empty_DB;
    CFunctions half_filled_DB;
    CFunctions fulled_DB;
};

/* Testing with Parameter Settings */
using ::testing::TestWithParam;
using ::testing::Values;
typedef CFunctions* DB_select();
CFunctions* DB1() {return new CFunctions(0);}
CFunctions* DB2() {return new CFunctions(47);}
CFunctions* DB3() {return new CFunctions(81);}
CFunctions* DB4() {return new CFunctions(95);}

class DBTesting : public TestWithParam<DB_select*>{
  public:
  ~DBTesting() override { delete DB; }

  void SetUp() override 
  {
    DB = (*GetParam())(); 
  }
  void TearDown() override 
  {
    delete DB;
    DB = nullptr;
  }

  protected:
  CFunctions* DB;
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
    std::cout<<"\n";
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

TEST_P(DBTesting, Test1){
  EXPECT_EQ(DB->getIndex(), DB->Insert(1));
}

INSTANTIATE_TEST_SUITE_P( Testing_with_param ,DBTesting , Values(DB1,DB2,DB3,DB4) );

}  // namespace
