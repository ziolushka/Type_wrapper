#pragma once
#include <typeinfo>
#include <string>

class AnyType
{
    union Data {
        double as_double;
        char as_char;
        bool as_bool;
        int as_int;
        float as_float;
    } m_value;

    enum Type {
        Bool,
        Char,
        Int,
        Double,
        Float
    } m_type;

public:

    AnyType()
    {
        m_value.as_double = 0.0;
    }

    template <typename T>
    AnyType(T value_)
    {

        std::string typeid_name = typeid(value_).name();

        if (typeid_name == typeid(bool).name()) {
            m_value.as_bool = static_cast<bool>(value_);
            m_type = Type::Bool;
        }
        else if (typeid_name == typeid(char).name()) {
            m_value.as_char = static_cast<char>(value_);
            m_type = Type::Char;
        }
        else if (typeid_name == typeid(int).name()) {
            m_value.as_int = static_cast<int>(value_);
            m_type = Type::Int;
        }
        else if (typeid_name == typeid(double).name()) {
            m_value.as_double = static_cast<double>(value_);
            m_type = Type::Double;
        }
        else if (typeid_name == typeid(float).name()) {
            m_value.as_float = static_cast<float>(value_);
            m_type = Type::Float;
        }
        else
            throw "Bad_cast caught: Fundamental types only!";

    }

    AnyType(const AnyType& atObj)
    {
        m_value = atObj.m_value;
        m_type = atObj.m_type;
    }

    template <typename T>
    AnyType& operator= (T value_)
    {

        std::string typeid_name = typeid(value_).name();

        if (typeid_name == typeid(bool).name()) {
            m_value.as_bool = static_cast<bool>(value_);
            m_type = Type::Bool;
        }
        else if (typeid_name == typeid(char).name()) {
            m_value.as_char = static_cast<char>(value_);
            m_type = Type::Char;
        }
        else if (typeid_name == typeid(int).name()) {
            m_value.as_int = static_cast<int>(value_);
            m_type = Type::Int;
        }
        else if (typeid_name == typeid(double).name()) {
            m_value.as_double = static_cast<double>(value_);
            m_type = Type::Double;
        }
        else if (typeid_name == typeid(float).name()) {
            m_value.as_float = static_cast<float>(value_);
            m_type = Type::Float;
        }
        else
            throw "Bad_cast caught: Fundamental types only!";

        return *this;
    }

    AnyType& operator=(const AnyType atObj)
    {
        if (&atObj == this)
            return *this;
        m_value = atObj.m_value;
        m_type = atObj.m_type;
        return *this;
    }
    ///
    /// \brief swap
    /// \param atObj
    ///Swaps two objects of AnyType class
    void swap(AnyType& atObj)
    {

        AnyType temp = *this;
        *this = atObj;
        atObj = temp;
    }
    ///
    /// \brief getType
    /// \return
    ///Returns the type of the contained value
    std::string get_type() const
    {

        switch (m_type) {
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
    T get_value() const
    {
        char current_type = static_cast<char>(get_type()[0]);

        if (current_type == *typeid(T).name())
            switch (m_type)
            {
            case Type::Int:
                return m_value.as_int;
            case Type::Float:
                return m_value.as_float;
            case Type::Double:
                return m_value.as_double;
            case Type::Bool:
                return m_value.as_bool;
            case Type::Char:
                return m_value.as_char;
            }
        else
            throw "Bad_cast caught: Wrong type of stored value!";
    }
};

