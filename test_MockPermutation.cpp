/**
 * Tests for mockPermutation data structure
 * 
 * @author Jeremy Perez
 * @date Febuary 2023
*/

#include <vector>
#include <string>
#include "mockPermutation.h"
#include <gtest/gtest.h>

using namespace std;

  mockPermutation testIDP = mockPermutation(5);


/*
  Test Non-Default Constructor: IDENTITY OF LENGTH
*/
TEST(MockPermutation, IdentityConstructor){

  EXPECT_EQ(5,testIDP.getLength());
  EXPECT_TRUE(testIDP.isId());
}

/*
  Test Non-Default Constructor: ARRAY and SIZE
*/
TEST(Mock_Permutation, SequenceConstructor){
  int seq[] =  {1,2,4,3};
  int seq2[] =  {1};

  mockPermutation test = mockPermutation(4,seq);
  mockPermutation test2 = mockPermutation(1,seq2);

  
  EXPECT_EQ(4, test.getLength());
  EXPECT_FALSE(test.isId());

  
  EXPECT_EQ(1, test2.getLength());
  EXPECT_TRUE(test2.isId());
}


/*
  Test Non-Default Constructor: VECTOR
*/
TEST(Mock_Permutation, VectorConstructor){
  vector<int> testVec =  {3,1,2};
  vector<int> testVec2 =  {1,2,3,4,5};


  mockPermutation test = mockPermutation(testVec);
  mockPermutation test2 = mockPermutation(testVec2);

  
  EXPECT_EQ(3, test.getLength());
  EXPECT_FALSE(test.isId());

  
  EXPECT_EQ(5, test2.getLength());
  EXPECT_TRUE(test2.isId());
}

/*
  Test Apply to Identity mockPermutation
*/
TEST(Mock_Permutation, apply){
  vector<int> testVec =  {3,1,2,4};
  mockPermutation test = mockPermutation(testVec);

  EXPECT_EQ(3,test.apply(1));
  EXPECT_EQ(1,test.apply(2));
  EXPECT_EQ(2,test.apply(3));
  EXPECT_EQ(4,test.apply(4));
  EXPECT_EQ(-1,test.apply(6));
  EXPECT_EQ(-1,test.apply(0));
  EXPECT_EQ(-1,test.apply(-1));
}

/**
 * Testing getLength function of the mockPermutation
*/
TEST(Mock_Permutation, getLength){
  vector<int> testVec =  {3,1,2,4};
  mockPermutation test = mockPermutation(testVec);
  vector<int> testVec1 =  {3};
  mockPermutation test1 = mockPermutation(testVec1);
  vector<int> testVec2 =  {};
  mockPermutation test2 = mockPermutation(testVec2);

  EXPECT_EQ(4,test.getLength());
  EXPECT_EQ(1,test1.getLength());
  EXPECT_EQ(0,test2.getLength());
}

/**
 * Test for Compose function
*/
TEST(Mock_Permutation, compose){
  vector<int> testVec =  {3,1,2,4};
  vector<int> testVec2 =  {1,4,2,3};


  mockPermutation test = mockPermutation(testVec);
  mockPermutation test2 = mockPermutation(testVec2);

  mockPermutation result1 = test.compose(test2);
  mockPermutation result2 = test2.compose(test);
  mockPermutation result3 = test.compose(test);

  EXPECT_EQ(0, result1.toString().compare("3 2 4 1"));
  EXPECT_EQ(0, result2.toString().compare("4 2 1 3"));
  EXPECT_TRUE(result3.isId());
}
/**
 * Test toString method
*/
TEST(Mock_Permutation, toString){
  vector<int> testVec =  {3,1,2,4};
  vector<int> testVec2 =  {1,4,2,3};


  mockPermutation test = mockPermutation(testVec);
  mockPermutation test2 = mockPermutation(testVec2);
  mockPermutation test3 = mockPermutation(1);

  EXPECT_EQ(0, test.toString().compare("3 1 2 4"));
  EXPECT_EQ(0, test2.toString().compare("1 4 2 3"));
  EXPECT_EQ(0, test3.toString().compare("1"));
}
/**
 * Test for isIdentity function
*/
TEST(Mock_Permutation, isId){
  vector<int> testVec =  {3,1,2,4};
  vector<int> testVec2 =  {1,4,2,3};

  mockPermutation test = mockPermutation(testVec);
  mockPermutation test1 = mockPermutation(testVec2);
  mockPermutation test2 = mockPermutation(0);

  EXPECT_FALSE(test.isId());
  EXPECT_FALSE(test1.isId());
  EXPECT_TRUE(test2.isId());

}
/**
 * Test Comparing methods between mockPermutation
*/
TEST(Mock_Permutation, compareTo){
  vector<int> testVec =  {3,1,2,4};
  vector<int> testVec2 =  {1,4,2,3};

  mockPermutation test = mockPermutation(testVec);
  mockPermutation test2 = mockPermutation(testVec2);

  EXPECT_GT(test.compareTo(test2),0);
  EXPECT_LT(test2.compareTo(test),0);
  EXPECT_EQ(0, test.compareTo(test));
}
/**
 * Test to check equal methods between mockPermutation
*/
TEST(Mock_Permutation, equals){
  vector<int> testVec =  {3,1,2,4};
  vector<int> testVec2 =  {1,4,2,3};

  mockPermutation test = mockPermutation(testVec);
  mockPermutation test2 = mockPermutation(testVec2);

  EXPECT_FALSE(test.equals(test2));
  EXPECT_FALSE(test2.equals(test));
  EXPECT_TRUE(test.equals(test));
}
/**
 * Test if Next correctly computes next permutation
*/
TEST(Mock_Permutation, next){
  vector<int> testVec =  {1,2,3};

  mockPermutation test = mockPermutation(testVec);

  test = test.Next();
  vector<int> perm1{1,3,2};
  EXPECT_TRUE(test.equals(mockPermutation(perm1)));


  test = test.Next();
  vector<int> perm2{2,1,3};
  EXPECT_TRUE(test.equals(mockPermutation(perm2)));


  test = test.Next();
  vector<int> perm3{2,3,1};
  EXPECT_TRUE(test.equals(mockPermutation(perm3)));


  test = test.Next();
  vector<int> perm4{3,1,2};
  EXPECT_TRUE(test.equals(mockPermutation(perm4)));


  test = test.Next();
  vector<int> perm5{3,2,1};
  EXPECT_TRUE(test.equals(mockPermutation(perm5)));


  test = test.Next();
  EXPECT_TRUE(test.equals(mockPermutation(3)));
}

GTEST_API_ int main(int argc, char **argv){
    printf("Running main() from test_MockPermutation.cpp\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
