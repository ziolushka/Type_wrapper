#include <iostream>
#include <typeinfo>
using namespace std;

class AnyType {

    union Data {
        double as_double;
        char as_char;
        bool as_bool;
        int as_int;
        float as_float;
    } value;

    enum Type {
        Bool,
        Char,
        Int,
        Double,
        Float
    } type;

public:

    AnyType(){
        value.as_double = 0.0;
    }

    template <typename T>
    AnyType(T value_){

        string typeid_name = typeid(value_).name();

        if (typeid_name == typeid(bool).name()) {
            value.as_bool = static_cast<bool>(value_);
            type = Type::Bool;
        }
        else if (typeid_name == typeid(char).name()) {
            value.as_char = static_cast<char>(value_);
            type = Type::Char;
        }
        else if (typeid_name == typeid(int).name()) {
            value.as_int = static_cast<int>(value_);
            type = Type::Int;
        }
        else if (typeid_name == typeid(double).name()) {
            value.as_double = static_cast<double>(value_);
            type = Type::Double;
        }
        else if (typeid_name == typeid(float).name()) {
            value.as_float = static_cast<float>(value_);
            type = Type::Float;
        }
        else
            throw "Bad_cast caught: Fundamental types only!";

    }

    AnyType(const AnyType &atObj){
        value = atObj.value;
        type = atObj.type;
    }

    template <typename T>

    AnyType& operator= (T value_){

        string typeid_name = typeid(value_).name();

        if (typeid_name == typeid(bool).name()) {
            value.as_bool = static_cast<bool>(value_);
            type = Type::Bool;
        }
        else if (typeid_name == typeid(char).name()) {
            value.as_char = static_cast<char>(value_);
            type = Type::Char;
        }
        else if (typeid_name == typeid(int).name()) {
            value.as_int = static_cast<int>(value_);
            type = Type::Int;
        }
        else if (typeid_name == typeid(double).name()) {
            value.as_double = static_cast<double>(value_);
            type = Type::Double;
        }
        else if (typeid_name == typeid(float).name()) {
            value.as_float = static_cast<float>(value_);
            type = Type::Float;
        }
        else
            throw "Bad_cast caught: Fundamental types only!";

        return *this;
    }

    AnyType& operator=(const AnyType atObj){

        if (&atObj == this)
            return *this;
        value = atObj.value;
        type = atObj.type;
        return *this;
    }
    ///
    /// \brief swap
    /// \param atObj
    ///Swaps two objects of AnyType class
    void swap(AnyType& atObj){

        AnyType temp = *this;
        *this = atObj;
        atObj = temp;
}
    ///
    /// \brief getType
    /// \return
    ///Returns the type of the contained value
    string getType() const {

        switch(type){
            case Type::Int:
               return "int";
            case Type::Float:
               return "float";
            case Type::Double:
               return "double";
            case Type::Bool:
               return "bool";
            case Type::Char:
               return "char";
        }
        return "empty";
    }

    template <typename T>
    ///
    /// \brief getValue
    /// \return
    ///Extracts a value should provide type-safe access. If the requested type does not match to stored type exception is thrown
    T getValue() const {
        char current_type = static_cast<char>(getType()[0]);

        if(current_type == *typeid(T).name())
            switch(type){
                case Type::Int:
                    return value.as_int;
                case Type::Float:
                    return value.as_float;
                case Type::Double:
                    return value.as_double;
                case Type::Bool:
                    return value.as_bool;
                case Type::Char:
                    return value.as_char;
            }
        else
            throw "Bad_cast caught: Wrong type of stored value!";
    }
};

int main()
{
    try {
        AnyType anyType;
        anyType = 126;
        anyType = true;
        anyType = 1.7;
        cout <<"Var 1 " << endl;
        cout <<"Type "<< anyType.getType()<<endl;
        cout <<"Value "<< anyType.getValue<double>()<< endl;

        AnyType anyType2 = 123;
        cout <<"Var 2 " << endl;
        cout <<"Type "<< anyType2.getType()<<endl;
        cout <<"Value "<< anyType2.getValue<int>()<< endl;

        swap(anyType,anyType2);
        cout <<"Swap" << endl;
        cout <<"Var 1 " << endl;
        cout <<"Type "<< anyType.getType()<<endl;
        cout <<"Value "<< anyType.getValue<int>()<< endl;
        cout <<"Var 2 " << endl;
        cout <<"Type "<< anyType2.getType()<<endl;
        cout <<"Value "<< anyType2.getValue<double>()<< endl;

        anyType2 = anyType;
        cout <<"Var 2 = Var 1 " << endl;
        cout <<"Var 1 " << anyType.getValue<int>()<< endl;
        cout <<"Var 2 " << anyType2.getValue<int>()<< endl;


        anyType2 = 126.5f;
        cout <<"Cast " << endl;
        cout <<"Var 2 = 126.5f" << endl;
        cout <<"Extract float "<< anyType2.getValue<float>()<< endl;
        cout <<"Extract char "<< anyType2.getValue<char>()<< endl;

    }
    catch (const char* msg) {
         cerr << msg << endl;
    }

}
