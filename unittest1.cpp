#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Alex\source\repos\Cursework4\Cursework4\Cursework4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(minn)
		{
			int one = 5;
			int two = 8;
			int minimum = min(one, two);
			Assert::AreEqual(5, minimum);
		}
		TEST_METHOD(minn2)
		{
			int one = 8;
			int two = 3;
			int minimum = min(one, two);
			Assert::AreEqual(3, minimum);
		}
		TEST_METHOD(checkchar1)
		{
			char *semb = "abcde";
			char test = 'c';
			Assert::AreEqual(checkchar(semb, test), true);
		}
		TEST_METHOD(checkchar2)
		{
			char *semb = "abcde";
			char test = 'f';
			Assert::AreEqual(checkchar(semb, test), false);
		}
		TEST_METHOD(findindex1)
		{
			char *semb = "abcde";
			char test = 'c';
			Assert::AreEqual(findindex(semb,test), 2);
		}
		TEST_METHOD(findindex2)
		{
			char *semb = "abcde";
			char test = 'e';
			Assert::AreEqual(findindex(semb, test), 4);
		}
		TEST_METHOD(findindex3)
		{
			char *semb = "abcde";
			char test = 'x';
			Assert::AreEqual(findindex(semb, test), INT_MAX);
		}

		TEST_METHOD(edgecount1)
		{
			Assert::AreEqual(8, countedge());
		}
		TEST_METHOD(edgecount2)
		{
			Assert::AreEqual(0, countedge());
		}
		TEST_METHOD(secondcheck1)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false,secondcheck(tex, edges));
			file.close();
		}
		TEST_METHOD(secondcheck2)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(true, secondcheck(tex, edges));
		}
		TEST_METHOD(count1)
		{
			Assert::AreEqual(6, count());
		}
		TEST_METHOD(count2)
		{
			Assert::AreEqual(0, count());
		}
		TEST_METHOD(firstcheck1)
		{
			Assert::AreEqual(true, firstcheck());
		}
		TEST_METHOD(firstcheck2)
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(firstcheck3)
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(firstcheck4)
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(maincheck1)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(true, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck2)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck3)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck4)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(BFS1)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			int tops = count();
			int **matrix = new int*[tops];
			for (int i = 0;i < tops;i++) {
				matrix[i] = new int[tops];
			}
			for (int i = 0;i < tops;i++)
				for (int j = 0;j < tops;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[tops];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checkchar(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checkchar(formatrix, tex[f].line[1]) == false) {
					formatrix[ji] = tex[f].line[1];
					ji++;
				}
			}
			for (int i = 0;i < edges;i++) {
				int x = findindex(formatrix, tex[i].line[0]);
				int y = findindex(formatrix, tex[i].line[1]);
				string help = " ";
				help[0] = tex[i].line[2];
				int index = stoi(help);
				matrix[x][y] = index;
			}
			int *parent = new int[tops];
			Assert::AreEqual(true, BFS(matrix,0,tops-1,parent,tops));
			file.close();
		}
		TEST_METHOD(BFS2)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			int tops = count();
			int **matrix = new int*[tops];
			for (int i = 0;i < tops;i++) {
				matrix[i] = new int[tops];
			}
			for (int i = 0;i < tops;i++)
				for (int j = 0;j < tops;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[tops];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checkchar(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checkchar(formatrix, tex[f].line[1]) == false) {
					formatrix[ji] = tex[f].line[1];
					ji++;
				}
			}
			for (int i = 0;i < edges;i++) {
				int x = findindex(formatrix, tex[i].line[0]);
				int y = findindex(formatrix, tex[i].line[1]);
				string help = " ";
				help[0] = tex[i].line[2];
				int index = stoi(help);
				matrix[x][y] = index;
			}
			int *parent = new int[tops];
			Assert::AreEqual(false, BFS(matrix, 0, tops - 1, parent, tops));
			file.close();
		}
		TEST_METHOD(max_flow1)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			int tops = count();
			int **matrix = new int*[tops];
			for (int i = 0;i < tops;i++) {
				matrix[i] = new int[tops];
			}
			for (int i = 0;i < tops;i++)
				for (int j = 0;j < tops;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[tops];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checkchar(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checkchar(formatrix, tex[f].line[1]) == false) {
					formatrix[ji] = tex[f].line[1];
					ji++;
				}
			}
			for (int i = 0;i < edges;i++) {
				int x = findindex(formatrix, tex[i].line[0]);
				int y = findindex(formatrix, tex[i].line[1]);
				string help = " ";
				help[0] = tex[i].line[2];
				int index = stoi(help);
				matrix[x][y] = index;
			}
			int testing = max_flow(matrix, 0,tops-1, tops);
			Assert::AreEqual(testing, 5);
			file.close();
		}
		TEST_METHOD(max_flow2)
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char test;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = test;
						i++;
						file >> test;
					}
					else
						file >> test;
					while (i < 3) {
						tex[j].line[i] = test;
						i++;
						file >> test;
						check = 1;
					}
					j++;
				}
			}
			int tops = count();
			int **matrix = new int*[tops];
			for (int i = 0;i < tops;i++) {
				matrix[i] = new int[tops];
			}
			for (int i = 0;i < tops;i++)
				for (int j = 0;j < tops;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[tops];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checkchar(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checkchar(formatrix, tex[f].line[1]) == false) {
					formatrix[ji] = tex[f].line[1];
					ji++;
				}
			}
			for (int i = 0;i < edges;i++) {
				int x = findindex(formatrix, tex[i].line[0]);
				int y = findindex(formatrix, tex[i].line[1]);
				string help = " ";
				help[0] = tex[i].line[2];
				int index = stoi(help);
				matrix[x][y] = index;
			}
			int testing = max_flow(matrix, 0, tops - 1, tops);
			Assert::AreEqual(testing, 0);
			file.close();
		}
	};
}