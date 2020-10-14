#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\TypeWrapper\TypeWrapper\AnyType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TypeWrapperUnitTests
{
	TEST_CLASS(TypeWrapperUnitTests)
	{
	public:
		
		TEST_CLASS_INITIALIZE(TypewrapperTestsInit)
		{
			Logger::WriteMessage("TypewrapperTestsInit");
		}
		TEST_CLASS_CLEANUP(TypewrapperTestsClean)
		{
			Logger::WriteMessage("TypewrapperTestsClean");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestDefault)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestDefault)
		{
			AnyType anytypeObj;
			Assert::IsTrue(anytypeObj.get_type() == "empty");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestInt)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestInt)
		{
			AnyType anytypeObj(12345);
			Assert::IsTrue(anytypeObj.get_value<int>() == 12345);
			Assert::AreEqual(anytypeObj.get_type(), std::string("int"), L"Should be int");

		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestFloat)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestFloat)
		{
			AnyType anytypeObj(24.78f);
			Assert::IsTrue(anytypeObj.get_value<float>() == 24.78f);
			Assert::AreEqual(anytypeObj.get_type(), std::string("float"), L"Should be float");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestDouble)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestDouble)
		{
			AnyType anytypeObj(23.22);
			Assert::IsTrue(anytypeObj.get_value<double>() == 23.22);
			Assert::AreEqual(anytypeObj.get_type(), std::string("double"), L"Should be double");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestBool)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestBool)
		{
			AnyType anytypeObj(true);
			Assert::IsTrue(anytypeObj.get_value<bool>() == true);
			Assert::AreEqual(anytypeObj.get_type(), std::string("bool"), L"Should be bool");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(InitTestChar)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(InitTestChar)
		{
			AnyType anytypeObj('a');
			Assert::IsTrue(anytypeObj.get_value<char>() == 'a');
			Assert::AreEqual(anytypeObj.get_type(), std::string("char"), L"Should be char");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(CopyConstructorTest)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(CopyConstructorTest)
		{
			AnyType anytypeObj(5);
			AnyType anytypeObj_copy(anytypeObj);
			Assert::IsTrue(anytypeObj_copy.get_value<int>() == anytypeObj.get_value<int>());
			Assert::AreEqual(anytypeObj_copy.get_type(), std::string("int"), L"Should be int");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(CopyAssigmentTest)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(CopyAssigmentTest)
		{
			AnyType anytypeObj = 5;
			AnyType anytypeObj_copy = anytypeObj;
			Assert::IsTrue(anytypeObj_copy.get_value<int>() == anytypeObj.get_value<int>());
			Assert::AreEqual(anytypeObj_copy.get_type(), std::string("int"), L"Should be int");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(SwapTest)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(SwapTest)
		{
			AnyType anytypeObj_b = true, anytypeObj_d = 34.999;
			Assert::AreEqual(anytypeObj_b.get_type(), std::string("bool"), L"Should be bool");
			Assert::AreEqual(anytypeObj_d.get_type(), std::string("double"), L"Should be double");

			anytypeObj_b.swap(anytypeObj_d);

			Assert::AreEqual(anytypeObj_d.get_type(), std::string("bool"), L"Should be bool");
			Assert::IsTrue(anytypeObj_d.get_value<bool>() == true);
			Assert::AreEqual(anytypeObj_b.get_type(), std::string("double"), L"Should be double");
			Assert::IsTrue(anytypeObj_b.get_value<double>() == 34.999);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(GetTypePossitive)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(GetTypePossitive)
		{
			AnyType anytypeObj(23.22);
			Assert::IsTrue(anytypeObj.get_type() == "double");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(GetTypeNagative)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(GetTypeNagative)
		{
			AnyType anytypeObj(true);
			Assert::IsFalse(anytypeObj.get_type() == "double");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(SafeCastPossitive)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(SafeCastPossitive)
		{
			AnyType anytypeObj = true;
			Assert::IsTrue(anytypeObj.get_value<bool>() == true);
			Assert::AreEqual(anytypeObj.get_type(), std::string("bool"), L"Should be bool");

			anytypeObj = 122444;
			Assert::IsTrue(anytypeObj.get_value<int>() == 122444);
			Assert::AreEqual(anytypeObj.get_type(), std::string("int"), L"Should be int");

		}
		BEGIN_TEST_METHOD_ATTRIBUTE(SafeCastNegative)
			TEST_OWNER(L"Olenka")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(SafeCastNegative)
		{
			AnyType anytypeObj = 122444;
			Assert::IsTrue(anytypeObj.get_value<int>() == 122444);

			auto funv = [&] {anytypeObj.get_value<char>(); };
			Assert::ExpectException<const char* >(funv);

		}
	};
}
