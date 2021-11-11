#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(SelectTest, SelectColumn){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    //sheet.set_selection(new Select_Contains(&sheet, "First","Amanda"));
    Select_Column* test = new Select_Contains(&sheet,"First","Amanda");
	bool result =  test->select(&sheet,1);
	//std::stringstream test;
    //sheet.print_selection(test); 
//EXPECT_EQ(result,true);
	//EXPECT_EQ(test.str(),"Amanda Andrews 22 business");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
