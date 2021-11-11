#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include <cstring> 
#include "select.hpp"
#include "spreadsheet.hpp"

class Select_And:public Select{ 
private: 
    Select* select1;
    Select* select2;  
public: 
    Select_And(Select* new_select1, Select* new_select2) { 
	 select1 = new_select1;
	 select2 = new_select2; 
    }
    virtual bool select(const Spreadsheet* sheet, int row) const {
	if(select1->select(sheet, row) && select2->select(sheet, row)){ return true;}
	else { return false; }  
    }
    ~Select_And(){
      delete select1;
      delete select2;  
    }
}; 
#endif
