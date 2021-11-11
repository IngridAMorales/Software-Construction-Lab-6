#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include <cstring>
#include "select.hpp"

class Select_Or : public Select{
private:

Select* select1;
Select* select2;
public:

     Select_Or(Select* nselect1, Select* nselect2){

	select1 = nselect1;
	select2 = nselect2;

	}
     bool select (const Spreadsheet* sheet, int row) const{
	if (select1->select(sheet,row)||select2->select(sheet,row)){
		return true;
}
	else{
		return false;
}	
}
~Select_Or(){
        delete select1;
	delete select2;
}
};





#endif //__SELECT_OR_HPP__
