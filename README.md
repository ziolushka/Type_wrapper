# Type_wrapper

**Task:** As a developer I want to have a class that can store single values of C++ fundamental type (except void and std::nullptr_t) and a function/method performs type-safe access to the conteined value, so that I will be able use a single variable to store an int, then a double, then a bool etc.

**Requirements:**

1. The class should contain all type of constructors
2. The class should contain all type of assignment operators
3. The class should contain a method to destroy contained object
4. The class should contain a method to swap two objects
5. The class should contain a method returns the type of the contained value
6. The function/method that extracts a value should provide type-safe access. If the requested type does not match to stored type exception should be thrown

**Implementation:** Main idea is to use a union and enum type variables to store current type and value of AnyType object.
