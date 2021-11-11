#ifndef __SELECT_NOT_HPP__
#define __SELCT_NOT_HPP__
#include "spreadsheet.hpp"
#include "select.hpp"
#include <cstring>

class Select_Not: public Select{
private:
    Select* select1;
   
public:
    Select_Not(Select* new_select1){
         select1 = new_select1;
    }
    virtual bool select(const Spreadsheet* sheet, int row) const {
	if (!(select1->select(sheet, row))){
	   return true;  
    	}
	else{ return false; }
    }
   ~Select_Not() { 
       delete select1; 
    }
};
#endif
