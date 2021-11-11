#include "spreadsheet.hpp"
#include "select.hpp"
#include "select_not.hpp"
#include "gtest/gtest.h"

TEST(SelectNotTest, SelectContainsTrue){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Not(new Select_Contains(&sheet, "First", "w"));
    bool result = test->select(&sheet,1); 

    EXPECT_EQ(result, true);
    delete test; 
}
TEST(SelectNotTest, SelectContainsFalse){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Not(new Select_Contains(&sheet, "First", "a"));
    bool result = test->select(&sheet,1);

    EXPECT_EQ(result, false);
    delete test;
}


