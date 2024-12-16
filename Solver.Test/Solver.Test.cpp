#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Solvertest
{
    TEST_CLASS(ListTest)
    {
    public:
        TEST_METHOD(AddElements_IntData_Success)
        {
            List<int> list; 
            list.add(1);
            list.add(2);
            list.add(3);
            Assert::AreEqual(size_t(3), list.getSize());
            Assert::AreEqual(1, list.get(0));
            Assert::AreEqual(2, list.get(1));
            Assert::AreEqual(3, list.get(2));
        }
    
        TEST_METHOD(RemoveElements_IntData_Success)
        {
            List<int> list; 
            list.add(1);
            list.add(2);
            list.add(3);
            list.remove(1);
            Assert::AreEqual(size_t(2), list.getSize());
            Assert::AreEqual(1, list.get(0));
            Assert::AreEqual(3, list.get(1));
        }
    
        TEST_METHOD(Remove_OutOfRange_ThrowsException)
        {
            List<int> list;
            Assert::ExpectException<std::out_of_range>([&]() { list.remove(0); });
        }
    
        TEST_METHOD(Get_EmptyList_ThrowsException)
        {
            List<int> list;
            Assert::ExpectException<std::out_of_range>([&]() { list.get(0); });
        }
    
        TEST_METHOD(Resize_IntData_Success)
        {
            List<int> list; 
            for (int i = 0; i < 100; ++i) 
            {
                list.add(i);
            }
            Assert::AreEqual(size_t(100), list.getSize());
            Assert::AreEqual(99, list.get(99));
        }
    
        TEST_METHOD(ToString_EmptyList_Success)
        {
            List<int> list;
            Assert::AreEqual(std::string(""), list.toString());
        }
    
        TEST_METHOD(ToString_IntData_Success)
        {
            List<int> list; 
            list.add(1);
            list.add(2);
            list.add(3);
            Assert::AreEqual(std::string("1 2 3"), list.toString());
        }
        
        TEST_METHOD(InputElements_IntData_Success)
        {
            List<int> list; 
            std::istringstream input("3 4 5 6");
            list.inputElements(input);
            Assert::AreEqual(size_t(4), list.getSize());
            Assert::AreEqual(3, list.get(0));
            Assert::AreEqual(4, list.get(1));
            Assert::AreEqual(5, list.get(2));
            Assert::AreEqual(6, list.get(3));
        }
    
        TEST_METHOD(RemoveElementByUser_IntData_Success)
        {
            List<int> list; 
            list.add(1);
            list.add(2);
            list.add(3);
            std::istringstream input("1");
            list.removeElementByUser(input);
            Assert::AreEqual(size_t(2), list.getSize());
            Assert::AreEqual(1, list.get(0));
            Assert::AreEqual(3, list.get(1));
        }
    };
}
