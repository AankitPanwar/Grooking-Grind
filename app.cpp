#include<iostream>
#include<stdio.h>
#include "singleTon.cpp"
using namespace std;
/* function uniqueFunction which take unique pointer of Single class as an argument */
void uniqueFunction(std::unique_ptr<Single> ptr)
{
    ptr->Set(30);
    std::cout << ptr->Get() << std::endl;
return;
} // end of the function

/* function uniqueFunction which take shared pointer of Single class as an argument */
void sharedFunction(std::shared_ptr<Single> ptr)
{
    ptr->Set(100);
    std::cout << " Shared pointer function value = " << ptr->Get() <<"  Reference count " << ptr.use_count()<< std::endl;
} // end of the fru

/* function that shows how weak pointer of Single calss can be declare and define*/
void weakPtr()
{
    std::shared_ptr<Single> sharedptr (Single::getInstance());
    std::weak_ptr<Single> weakptr = sharedptr;
}// end of the function

/* Function that define the share pointer defination for "single" class and it's implementation */
void sharedPtr()
{
    std::shared_ptr<Single> sptr (Single :: getInstance());
    std::cout << " Share pointer in main = " << sptr->Get() << std::endl;
    sharedFunction(sptr); // it pass pa
    if(sptr!=nullptr)
        std::cout << " Share pointer after function  = " << sptr->Get() << std::endl;
    else        
        return;
    std::cout << " Reference count = " << sptr.use_count() << std::endl;
return;
}

/* Function that define the share pointer defination for "single" class and it's implementation */
void uniquePtr()
{
    std::unique_ptr<Single> ptr ( Single::getInstance());
    ptr->Set(50);
    std::cout << ptr->Get() << std::endl;
    std::cout << " Unique pointer below function =  " << ptr->Get(); 
    uniqueFunction(std::move(ptr)); // the owenerShip has been transfered to the function argument ;
    if(ptr!=nullptr) // once the ownership is transferred , ptr points to the null ptr , so this condition will false;
        std::cout << ptr->Get() << std::endl;
    else    
       std::cout << " Ptr points to nullptr " << std::endl;
return ;
}

int main()
{
    /* Function call*/
    sharedPtr();  
return 0;
}// end of the main