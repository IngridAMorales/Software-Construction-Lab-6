#include "spreadsheet.hpp"
#include "select.hpp"
#include "select_or.hpp"
#include "gtest/gtest.h"


TEST(SelectOrTest, SelectContains){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Or(new Select_Contains(&sheet,"Last","on"),new Select_Contains(&sheet,"Age","22"));
	bool result = test->select(&sheet,0);
	EXPECT_EQ(result,true);
    delete test;
}

TEST(SelectOrTest, SelectContainsFalse){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Or(new Select_Contains(&sheet,"Last","on"),new Select_Contains(&sheet,"Age","21"));
        bool result = test->select(&sheet,0);
        EXPECT_EQ(result,false);
        delete test;

}

TEST(SelectOrTest, SelectContainsBothTrue){
    Spreadsheet sheet;
    sheet.set_column_names({"First","Last","Age","Major"});
    sheet.add_row({"Amanda","Andrews","22","business"});
    sheet.add_row({"Brian","Becker","21","computer science"});
    Select* test = new Select_Or(new Select_Contains(&sheet,"Last","And"),new Select_Contains(&sheet,"Age","22"));
        bool result = test->select(&sheet,0);
        EXPECT_EQ(result,true);
        delete test;

}

