#include "spreadsheet.hpp"
#include "select.hpp"
#include "select_not.hpp"
#include "select_and.hpp"
#include "gtest/gtest.h"

TEST(SelectAndTest, SelectContains){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    Select* test = new Select_And(new Select_Contains(&sheet,"Last","22"), new Select_Not(new Select_Contains(&sheet, "First", "w")));
    bool result = test->select(&sheet,1);

    EXPECT_EQ(result, false);
    delete test; 
}
TEST(SelectAndTest, SelectAndTrue){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    Select* test = new Select_And(new Select_Contains(&sheet,"Age","21"), new Select_Not(new Select_Contains(&sheet, "First", "w")));
    bool result = test->select(&sheet,1);

    EXPECT_EQ(result, true);
    delete test;    
}

TEST(SelectAndTest, SelectAndContainTrue){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    sheet.add_row({"Carol","Conners","21","computer science"});
    Select* test = new Select_And(new Select_Contains(&sheet,"Age","21"), new Select_Contains(&sheet,"First", "Brian"));
    bool result = test->select(&sheet,1);

    EXPECT_EQ(result, true);
    delete test; 
}

