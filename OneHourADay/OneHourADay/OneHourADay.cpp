// OneHourADay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
const double my_pi = 3.141592; // #define is a preprocessor macro

constexpr double getPi() { return 22.07 / 7; }

constexpr double TwicePi() { return 2 * getPi(); }

constexpr int Square(int number) { return number * number; }

// test

template<typename T>
class Sample
{
private:
    T* ptrSource;
public:
    Sample(Sample&& moveSource) // Move constructor, note &&
    {
        ptrSource = moveSource.ptrSource;
        moveSource.ptrSource = NULL;
    }

    Sample& operator=(Sample&& moveSource) // move assignment operator, note &&
    {
        if (this != &moveSource)
        {
            delete[] ptrSource; // free own resource
            ptrSource = moveSource.ptrSource; // take ownership, start move
            moveSource.ptrSource = NULL; // free move source of ownership
        }
    }
    Sample() = default; // default constructor
    Sample(const Sample& copySource); // copy constructor
    Sample& operator=(const Sample& copySource); // copy assignment

};

class President
{
private:
    friend class Utility;
    
    President() {}; // private default constructor
    President(const President&); // private copy constructor
    const President& operator=(const President&); // assignment operator

    string name;
    int age;
public:
    static President& getInstance()
    {
        static President onlyInstance;
        return onlyInstance;
    }

    string getName()
    {
        return name;
    }

    void setName(string inputName)
    {
        name = inputName;
    }


};

class Utility
{
public:
    static void DisplayAge(const President& person)
    {
        cout << person.age << endl;
    }
};

void Area(const double rad, double& result)
{
    result = my_pi * rad * rad;
}

void displayNums(std::vector<int>& dynArray)
{
    for_each(dynArray.begin(), dynArray.end(), 
        [](int Element) {std::cout << Element << " "; });
    std::cout << "\n";
}

void calcArea(const double* const ptrPi, const double* const ptrRadius, double* const ptrArea)
{
    if (ptrPi && ptrRadius && ptrArea)
    {
        *ptrArea = (*ptrPi) * (*ptrRadius) * (*ptrRadius);
    }
}

void GetSquare(const int& number, int& result)
{
    result = number * number;
}

class MyString
{
private:
    char* buffer;
    
public:
    MyString(const char* initialInput)
    {
        if (initialInput != NULL)
        {
            buffer = new char[strlen(initialInput) + 1];
            // strcpy(buffer, initialInput);
            strcpy_s(buffer, strlen(initialInput) + 1, initialInput);
        }
        else
        {
            buffer = NULL;
        }
    }

    MyString(MyString&& moveSrc) // move constructor
    {
        if (moveSrc.buffer != NULL)
        {
            buffer = moveSrc.buffer; // take ownership i.e. 'move'
            moveSrc.buffer = NULL; // free move source
        }
    }

    MyString& operator=(MyString&& moveSrc) // move assignment op.
    {
        if ((moveSrc.buffer != NULL) && (this != &moveSrc))
        {
            delete[] buffer; // release own buffer
            buffer = moveSrc.buffer; // take ownership i.e. 'move'
            moveSrc.buffer = NULL; // free move source
        }
        return *this;
    }

    // Copy assignment operator
    MyString& operator=(const MyString& copySource)
    {
        if ((this != &copySource) && (copySource.buffer != NULL))
        {
            if (buffer != NULL)
            {
                delete[] buffer;
            }

            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy_s(buffer, strlen(copySource.buffer)+1, copySource.buffer);
        }
        return *this;
    }
    operator const char* ()
    {
        return buffer;
    }

     char& operator[](int index) 
    {
        if(index < getLength())
        {
            return buffer[index];
        }
    }

    char& operator[](int index) const
    {
        if (index < getLength())
        {
            return buffer[index];
        }
    }

    // a function object created using operator ()
    void operator()(string input) const
    {
        cout << input << endl;
    }

    size_t getLength() const
    {
        return strlen(buffer);
    }
    ~MyString()
    {
        delete[] buffer;
    }
};


class Date
{
private:
    int day, month, year;
    string dateInString;
public:
    Date(int m, int d, int y) :month(m), day(d), year(y) {};

    Date& operator++() // prefix
    {
        ++day;
        return *this;
    }

    Date& operator--() // prefix
    {
        --day;
        return *this;
    }

    Date& operator++(int)
    {
        Date copy(month, day, year);
        ++day;
        return copy;
    }
    // overloaded versions of the addition assignment operator (+=)
    void operator-=(int daysToSub)
    {
        day -= daysToSub;
    }

    void operator+=(const Date& daysToAdd)
    {
        // days += daysToAdd.getDays();
    }

    bool operator==(const Date& compareTo)
    {
        return ((day == compareTo.day)
            && (month == compareTo.month)
            && (year == compareTo.year));
    }

    bool operator!=(const Date& compareTo)
    {
        return !(this->operator==(compareTo));
    }

    explicit operator const char* ()
    {
        std::ostringstream formattedDate;
        formattedDate << month << " / " << day << " / " << year;
        dateInString = formattedDate.str();
        return dateInString.c_str();
    }

    void displayDate()
    {
        cout << month << " / " << day << " / " << year << endl;
    }
};




int main()
{
    MyString displayFuncObj("h");
    displayFuncObj("Display");

    //the problem of "Narrowing Conversion" leads to List initialization { }
    // auto (automatic type inferance)
    auto t = true;
    //typedef (substitute a variable's type)
    typedef unsigned int Strictly_positive_integer;
    Strictly_positive_integer numEggsInBasket = 4532;

    // const type-name constant-name = value;

    // M_PI <--- <cmath>

    int solarPanels[2][3] = { {0, 1, 2}, {3, 4, 5} };
    char sayHello[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd','\0' };
    // string-terminating character
    // lvalue vs. rvalue
    // prefix increment, prefix decrement, postfix increment, prefix decrement
    // bitset<8>
    // function declaration, function arguments, function parameters, function definition (implementations)
    // overloading functions

    double radius = 10;
    double result = 0;
    Area(radius, result);
    std::cout << "area : " << result << "\n";
    // Last-In-First-Out, push operation, pop operation
     // inline : increase the execution speed of the code

    vector<int> myNums;
    myNums.push_back(501);
    myNums.push_back(-1);
    myNums.push_back(25);
    myNums.push_back(-35);
    displayNums(myNums);
    cout << "Sorting them in descending order" << endl;
    sort(myNums.begin(), myNums.end(),
        [](int Num1, int Num2) {return (Num2 < Num1); });

    displayNums(myNums);

    int age = 30;
    cout << &age << endl; // address in memory, referencing operator (&) == address-of operator
    // dereference operator (*) === indirection operator
    int* pointsToInt = &age;
    cout << "pointsToInt points to age now" << endl;
    // Displaying the value of pointer
    cout << "pointsToInt = 0x" << std::hex << pointsToInt << endl;
    cout << "sizeof(double*) = " << sizeof(double*) << endl;

    // dynamic memory allocation "new" or "delete" to allocation and release memory dynamically
    int* pntToNums = new int[10];
    // delete is to release a block of memomry allocated
    double area = 0;
    calcArea(&my_pi, &radius, &area);
    // danglingling pointers (stray or wild pointers)
    //pass by reference
    int number = 10;
    int* n1 = new int{ 3 };

    int square = 0;
    GetSquare(*n1, square);
    cout << "square : " << square << endl;
    delete n1;
    n1 = nullptr;
    // dot operator, pointer operator (->), indirection operator (*)
    // private class members can be used only within the class (or its "friends")
    // :: scope resolution operator

    // shallow copying
    // this is a copy generated by the compiler as the function has been declared to take str as a parameter by value
    //  and not by reference.

    //Singleton
    President& onlyPresident = President::getInstance();
    onlyPresident.setName("Abraham Lincoln");
    cout << President::getInstance().getName() << endl;


    President& onlyPresident2 = President::getInstance();
    onlyPresident2.setName("Abraham Lincoln2");
    cout << President::getInstance().getName() << endl;

    // The compiler knows that class Human supports a constructor that accepts an integer and performed an 
    // implicit conversion for you -- it created an object of type Human using the integer you supplied and sent it as an
    // argument to the function
    // to avoid implicit conversions, use keyword explicit as the time of declaring the constructor

    // "this" contains the address of the object. the value of this is &object

    // word padding

    // aggregate initialization, using aggregate initialization on classes and structs
    // constexpr with classes and objects

    // protected - access specifier
    // myDinner.Fish::Swim();

    // :: scope resolution operator(::)

    // to avoid slicing problems, don't pass parameters by value. 
    // Pass tehm as pointers to the base class or as a (optionally const) reference to the same.


    Date holiday(12, 25, 2016);
    cout << static_cast<const char*>(holiday) << endl;

    // Using explicit would force the programmer to assert his intention to covert using a cast:
    string strHolidya {static_cast<const char*>(Date(11, 11, 2016))};

    auto smtInt = std::make_unique<int>();
    *smtInt = 4;
    cout << *smtInt << endl;

    std::unique_ptr<Date> smartHoliday(new Date(12, 25, 2016));

}
           
class Fish
{
public: 
    virtual void swim() // virtual means that the compiler ensures that any overriding variant of the requested base class
        // method is invoked.
    {
        cout << "Fish swim" << endl;
    }
};

class Tuna : public Fish
{
public:
    void swim() override
    {
        cout << "Tuna swim" << endl;
    }
};

void makeFishSwim(Fish& inputFish)
{
    inputFish.swim();
}
// Virtual Function Table (VFT), each table is comprised of function pointers

class AbstractBase
{
public:
    virtual void doSomething() = 0; // pure virtual method ---> pure virtual function must be implemented in the derived class
};

/// Abstract Base Classes are often simply called ABCs.

// override : supplies a powerful way of expressing the explicit intention to override a base class virtual function
// "final" to prevent function overriding

// unary operators

