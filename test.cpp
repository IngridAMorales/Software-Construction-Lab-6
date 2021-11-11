#include "spreadsheet.hpp"
#include "select.hpp"
#include "gtest/gtest.h"

TEST(SelectTest, SelectColumn){

    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    //sheet.set_selection(new Select_Column(&sheet, "First","Amanda"));
    Select* test = new Select_Contains(&sheet,"First","Amanda");
	bool result = test->select(&sheet,1);

	EXPECT_EQ(result,true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
