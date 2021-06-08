#include "pch.h"
#include "CppUnitTest.h"
#include "G:\Программирование\Тутуева\Kyrsa4_4sem\Kersa4_4sem\Kersa4_4sem\queue.h"
#include "G:\Программирование\Тутуева\Kyrsa4_4sem\Kersa4_4sem\Kersa4_4sem\function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			queue* que = new queue;
			std::ifstream file;
			std::string cities[6] = { "S","O","P","Q","R","T" };
			file.open("G:\\Программирование\\Тутуева\\Kyrsa4_4sem\\Kersa4_4sem\\Kersa4_4sem\\text.txt", std::ios::in);
			reading(que, file);
			for (int i = 0; i < que->get_size(); i++) 
			{
				Assert::IsTrue(que->at(i) == cities[i]);
			}
			file.close();
		}
		TEST_METHOD(TestMethod2)
		{
			queue* que = new queue;
			std::ifstream file;
			file.open("G:\\Программирование\\Тутуева\\Kyrsa4_4sem\\Kersa4_4sem\\Kersa4_4sem\\text_1.txt", std::ios::in);
			reading(que, file);
			int size = que->get_size();
			int** matrix;
			matrix = new int* [size];
			for (int i = 0; i < size; i++) 
			{
				matrix[i] = new int[size];
			}
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix[i][j] = 0;
				}
			}
			file.clear();
			file.seekg(0);
			int matrix_1[4][4] = { {0,3,1,0},{0,0,0,5},{0,1,0,3},{0,0,0,0} };
			creating_matrix(que, file, matrix, size);
			for (int i = 0; i < 4; i++) 
			{
				for (int j = 0; j < 4; j++) 
				{
					Assert::IsTrue(matrix[i][j] == matrix_1[i][j]);
				}
			}
			file.close();
			delete matrix;
		}
		TEST_METHOD(TestMethod3)
		{
			queue* que = new queue;
			std::ifstream file;
			file.open("G:\\Программирование\\Тутуева\\Kyrsa4_4sem\\Kersa4_4sem\\Kersa4_4sem\\text_1.txt", std::ios::in);
			reading(que, file);
			int size = que->get_size();
			int** matrix;
			matrix = new int* [size];
			for (int i = 0; i < size; i++)
			{
				matrix[i] = new int[size];
			}
			int** matrix_1 = new int* [size];
			for (int i = 0; i < size; i++) 
			{
				matrix_1[i] = new int[size];
			}
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix[i][j] = 0;
				}
			}
			file.clear();
			file.seekg(0);
			creating_matrix(que, file, matrix, size);
			Pushing_preflow(size, matrix, matrix_1);
			int flow = 0;
			for (int i = 0; i < size; i++)
				if (matrix[0][i])
					flow += matrix_1[0][i];
			file.close();
			delete matrix;
			Assert::IsTrue(flow == 4);
		}
		TEST_METHOD(TestMethod4)
		{
			try {
				queue* que = new queue;
				std::ifstream file;
				file.open("G:\\Программирование\\Тутуева\\Kyrsa4_4sem\\Kersa4_4sem\\Kersa4_4sem\\text_2.txt", std::ios::in);
				reading(que, file);
			}
			catch (const char* warning) 
			{
				Assert::AreEqual(warning, "incorrect input");
			}
		}
		TEST_METHOD(TestMethod5)
		{
			try {
				queue* que = new queue;
				std::ifstream file;
				file.open("G:\\Программирование\\Тутуева\\Kyrsa4_4sem\\Kersa4_4sem\\Kersa4_4sem\\text_3.txt", std::ios::in);
				reading(que, file);
				int size = que->get_size();
				int** matrix;
				matrix = new int* [size];
				for (int i = 0; i < size; i++) 
				{
					matrix[i] = new int[size];
				}
				for (int i = 0; i < size; i++) 
				{
					for (int j = 0; j < size; j++) 
					{
						matrix[i][j] = 0;
					}
				}
				file.clear();
				file.seekg(0);
				creating_matrix(que, file, matrix, size);
				file.close();
			}
			catch (const char* warning) {
				Assert::AreEqual(warning, "incorrect input");
			}
		}
	};
}
