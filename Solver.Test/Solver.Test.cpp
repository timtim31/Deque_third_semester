#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTest
{
    namespace ListTests
    {
        TEST_CLASS(SolverTest)
        {
        public:

            TEST_METHOD(TestMethod1)
            {
            }
        };

        TEST_CLASS(ListTest)
        {
        public:
            TEST_METHOD(AddElements_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
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
                List<int> list; // Указываем тип шаблона
                list.add(1);
                list.add(2);
                list.add(3);
                list.remove(1);
                Assert::AreEqual(size_t(2), list.getSize());
                Assert::AreEqual(1, list.get(0));
                Assert::AreEqual(3, list.get(1));
            }

            TEST_METHOD(GetElement_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
                list.add(1);
                list.add(2);
                list.add(3);
                Assert::AreEqual(1, list.get(0));
                Assert::AreEqual(2, list.get(1));
                Assert::AreEqual(3, list.get(2));
            }

            TEST_METHOD(Resize_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
                for (int i = 0; i < 100; ++i) 
                {
                    list.add(i);
                }
                Assert::AreEqual(size_t(100), list.getSize());
                Assert::AreEqual(99, list.get(99));
            }

            TEST_METHOD(ToString_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
                list.add(1);
                list.add(2);
                list.add(3);
                Assert::AreEqual(std::string("1 2 3"), list.toString());
            }

            TEST_METHOD(InputElements_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
                std::istringstream input("3\n4\n5\n6\n");
                std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf()); 
                list.inputElements();
                std::cin.rdbuf(cinbuf); 
                Assert::AreEqual(size_t(6), list.getSize());
                Assert::AreEqual(4, list.get(3));
                Assert::AreEqual(5, list.get(4));
                Assert::AreEqual(6, list.get(5));
            }

            TEST_METHOD(RemoveElementByUser_IntData_Success)
            {
                List<int> list; // Указываем тип шаблона
                list.add(1);
                list.add(2);
                list.add(3);
                std::istringstream input("1\n");
                std::streambuf* cinbuf = std::cin.rdbuf(input.rdbuf()); 
                list.removeElementByUser();
                std::cin.rdbuf(cinbuf); 
                Assert::AreEqual(size_t(2), list.getSize());
                Assert::AreEqual(1, list.get(0));
                Assert::AreEqual(3, list.get(1));
            }
        };
    }
}
