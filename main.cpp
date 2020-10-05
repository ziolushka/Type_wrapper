#include <iostream>
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
    ///
    /// \brief AnyType
    ///Default Constructor
    AnyType(){
        type = Type::Double;
        value.as_double = 0.0;
    }
    ///
    ///\brief AnyType
    ///Parameterized Constructor
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
    ///
    /// \brief AnyType
    /// \param atObj
    ///Copy constructor
    AnyType(const AnyType &atObj){
        value = atObj.value;
        type = atObj.type;
    }

    template <typename T>
    ///
    /// \brief operator =
    /// \param value_
    /// \return
    ///Assignment operator
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
    ///
    /// \brief operator =
    /// \param atObj
    /// \return
    ///Copy operator
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
    if(type == atObj.type){//switch
        switch(type){
        case Type::Int:
            std::swap(this->value.as_int, atObj.value.as_int);
            break;
        case Type::Float:
            std::swap(this->value.as_float, atObj.value.as_float);
            break;
        case Type::Double:
            std::swap(this->value.as_double, atObj.value.as_double);
            break;
        case Type::Bool:
            std::swap(this->value.as_bool, atObj.value.as_bool);
            break;
        case Type::Char:
            std::swap(this->value.as_char, atObj.value.as_char);
            break;
        }
    }
    std::swap(type, atObj.type);
}
    ///
    /// \brief getType
    /// \return
    ///Returns the type of the contained value
    string getType(){

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
    T getValue() {
        char current_type = static_cast<char>(getType()[0]);

        if(current_type == *typeid(T).name())
            switch(type){
                case Type::Int:
                    return static_cast<int>(value.as_int);
                case Type::Float:
                    return static_cast<float>(value.as_float);
                case Type::Double:
                    return static_cast<double>(value.as_double);
                case Type::Bool:
                    return static_cast<bool>(value.as_bool);
                case Type::Char:
                    return static_cast<char>(value.as_char);
            }
        else
            throw "Bad_cast caught: Wrong type of stored value!";

}
};

int main()
{
    try {
        AnyType anyType = 126;
        anyType = true;
        anyType = 1.7;
        cout << anyType.getType()<<endl;
        AnyType anyType2 = 54655;

        swap(anyType,anyType2);
        cout << anyType.getValue<int>()<< endl;

        anyType2 = anyType;
        cout << anyType2.getValue<int>()<< endl;
        cout << anyType.getValue<double>()<< endl;
        anyType2 = 126.5f;
        cout <<"Int "<< anyType2.getValue<int>()<< endl;
        cout <<"Double "<< anyType2.getValue<double>()<< endl;
        cout <<"Float "<< anyType2.getValue<float>()<< endl;
        cout <<"Bool "<< anyType2.getValue<bool>()<< endl;
        cout <<"Char "<< anyType2.getValue<char>()<< endl;

    }
    catch (const char* msg) {
         cerr << msg << endl;
    }

}
