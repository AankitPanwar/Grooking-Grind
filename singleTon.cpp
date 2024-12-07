/* 
	Singleton class with smart pointers
*/
#include<iostream>
#include<stdio.h>
#include<memory>
using namespace std;
class Single
{
    private:
        static Single* instance ;
        Single() = default;
        Single(const Single &) = delete; // disable the copy constructor functionality 
        Single& operator = (const Single &) = delete;   // disable the operator overloading functionality
    public:
        int val = 20;
        static Single* getInstance()
        {
            if(instance == nullptr)
                instance = new Single();
        return instance ; 
        }
        void Set(int value )
        {
            val = value;
        }
        int Get()
        {
                return val;
        }
    ~Single()
    {
        std::cout << " Destructor Called " << std::endl;
    }
};
Single* Single:: instance = nullptr;
void uniqueFunction(std::unique_ptr<Single> ptr)
{
    ptr->Set(30);
    std::cout << ptr->Get() << std::endl;
}
void sharedFunction(std::shared_ptr<Single> ptr)
{
    ptr->Set(100);
    std::cout << " Shared pointer function value = " << ptr->Get() <<"  Reference count " << ptr.use_count()<< std::endl;
}
void weakPtr()
{
    std::shared_ptr<Single> sharedptr (Single::getInstance());
    std::weak_ptr<Single> weakptr = sharedptr;
}
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
      uniquePtr();
//    sharedPtr();
//    weakPtr();
    return 0;
}
