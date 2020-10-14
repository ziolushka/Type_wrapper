// TypeWrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "AnyType.h"

int main()
{
    try
    {
        AnyType anyType;
        anyType = 126;
        anyType = true;
        anyType = 1.7;
        std::cout << "Var 1 " << std::endl;
        std::cout << "Type " << anyType.get_type() << std::endl;
        std::cout << "Value " << anyType.get_value<double>() << std::endl;

        AnyType anyType2 = 123;
        std::cout << "Var 2 " << std::endl;
        std::cout << "Type " << anyType2.get_type() << std::endl;
        std::cout << "Value " << anyType2.get_value<int>() << std::endl;

        std::swap(anyType,anyType2);
        std::cout << "Swap" << std::endl;
        std::cout << "Var 1 " << std::endl;
        std::cout << "Type " << anyType.get_type() << std::endl;
        std::cout << "Value " << anyType.get_value<int>() << std::endl;
        std::cout << "Var 2 " << std::endl;
        std::cout << "Type " << anyType2.get_type() << std::endl;
        std::cout << "Value " << anyType2.get_value<double>() << std::endl;

        anyType2 = anyType;
        std::cout << "Var 2 = Var 1 " << std::endl;
        std::cout << "Var 1 " << anyType.get_value<int>() << std::endl;
        std::cout << "Var 2 " << anyType2.get_value<int>() << std::endl;


        anyType2 = 126.5f;
        std::cout << "Cast " << std::endl;
        std::cout << "Var 2 = 126.5f" << std::endl;
        std::cout << "Extract float " << anyType2.get_value<float>() << std::endl;
        std::cout << "Extract char " << anyType2.get_value<char>() << std::endl;

    }
        catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
