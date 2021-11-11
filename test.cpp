#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(SelectTest, SelectContains){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    //sheet.set_selection(new Select_Contains(&sheet, "First","Amanda"));
    Select_Column* test = new Select_Contains(&sheet,"First","Amanda");
	bool result =  test->select(&sheet,0);
	//std::stringstream test;
    //sheet.print_selection(test); 
	EXPECT_EQ(result,true);
	//EXPECT_EQ(test.str(),"Amanda Andrews 22 business");
}

TEST(SelectTest, SelectContainsSubstring){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"First","man");                    bool result =  test->select(&sheet,0);                                          EXPECT_EQ(result,true);
}

TEST(SelectTest, SelectContainsAge){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"Age","21");         
           bool result =  test->select(&sheet,1);                                        EXPECT_EQ(result,true);
}

TEST(SelectTest, SelectContainsEmpty){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"Age","");
           bool result =  test->select(&sheet,1);                                        EXPECT_EQ(result,true);
}
TEST(SelectTest, SelectContainsColumnNotExist){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"Ages","21");
           bool result =  test->select(&sheet,1);                                        EXPECT_EQ(result,false);
}

TEST(SelectTest, SelectContainsDuplicateColumnFalse){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Age","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"Age","21");
           bool result =  test->select(&sheet,1);                                        EXPECT_EQ(result,false);
}

TEST(SelectTest, SelectContainsDuplicateColumnTrue){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Age","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Contains(&sheet,"Age","Andrews");
           bool result =  test->select(&sheet,0);                                        EXPECT_EQ(result,true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
