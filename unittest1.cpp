#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Alex\source\repos\Cursework4\Cursework4\Cursework4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(min1) //find min number, 1st case.
		{
			int one = 5;
			int two = 8;
			int minimum = min(one, two);
			Assert::AreEqual(5, minimum);
		}
		TEST_METHOD(min2)//find min number, 2nd case.
		{
			int one = 8;
			int two = 3;
			int minimum = min(one, two);
			Assert::AreEqual(3, minimum);
		}
		TEST_METHOD(checksymbol_true)// check symbol in array, true case.
		{
			char *semb = "abcde";
			char test = 'c';
			Assert::AreEqual(checksymbol(semb, test), true);
		}
		TEST_METHOD(checksymbol_false)// check symbol in array, false case.
		{
			char *semb = "abcde";
			char test = 'f';
			Assert::AreEqual(checksymbol(semb, test), false);
		}
		TEST_METHOD(findindex1)// find an index of symbol in array, 1st case.
		{
			char *semb = "abcde";
			char test = 'c';
			Assert::AreEqual(findindex(semb,test), 2);
		}
		TEST_METHOD(findindex2)// find an index of symbol in array, 2nd case.
		{
			char *semb = "abcde";
			char test = 'e';
			Assert::AreEqual(findindex(semb, test), 4);
		}
		TEST_METHOD(findindex_false)// find an index of symbol in array, false case.
		{
			char *semb = "abcde";
			char test = 'x';
			Assert::AreEqual(findindex(semb, test), INT_MAX);
		}

		TEST_METHOD(edgecount_good)//count edges in the file. File is filled
		{
			Assert::AreEqual(8, countedge());
		}
		TEST_METHOD(edgecount_empty)//count edges in the file. File is empty
		{
			Assert::AreEqual(0, countedge());
		}
		TEST_METHOD(secondcheck_uninitilized)// uninitilized vertex
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false,secondcheck(tex, edges));
			file.close();
		}
		TEST_METHOD(secondcheck_correct)// correct file
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(true, secondcheck(tex, edges));
		}
		TEST_METHOD(count1)// count vertex, 1st case
		{
			Assert::AreEqual(6, count());
		}
		TEST_METHOD(count2)// count vertex, 2nd case
		{
			Assert::AreEqual(0, count());
		}
		TEST_METHOD(firstcheck_correct)// correct file
		{
			Assert::AreEqual(true, firstcheck());
		}
		TEST_METHOD(firstcheck_numberfirst)// number on the first place
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(firstcheck_numbersecond)// number on the second place
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(firstcheck_letterthird)// letter on the third place
		{
			Assert::AreEqual(false, firstcheck());
		}
		TEST_METHOD(maincheck_correct)// correct file
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(true, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck_negative)// negative number
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck_source)// wrong source
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(maincheck_stock)//wrong stock
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			Assert::AreEqual(false, maincheck(tex, edges));
			file.close();
		}
		TEST_METHOD(BFS1) // BFS 1st case
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
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
				if (checksymbol(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checksymbol(formatrix, tex[f].line[1]) == false) {
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
		TEST_METHOD(BFS2) // BFS second case
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
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
				if (checksymbol(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checksymbol(formatrix, tex[f].line[1]) == false) {
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
		TEST_METHOD(max_flow_good)// max_flow 1st case
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			int vertexes = count();
			int **matrix = new int*[vertexes];
			for (int i = 0;i < vertexes;i++) {
				matrix[i] = new int[vertexes];
			}
			for (int i = 0;i < vertexes;i++)
				for (int j = 0;j < vertexes;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[vertexes];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checksymbol(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checksymbol(formatrix, tex[f].line[1]) == false) {
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
			int testing = max_flow(matrix, 0,vertexes-1, vertexes);
			Assert::AreEqual(testing, 5);
			file.close();
		}
		TEST_METHOD(max_flow_empty)// empty file
		{
			int edges = countedge();
			fstream file;
			text *tex = new text[edges];
			int check = 0;
			char symbol;
			int j = 0;
			file.open("C:\\Users\\Alex\\Desktop\\for test.txt", ios::in);
			if (firstcheck() == true) {
				while (!file.eof()) {
					int i = 0;
					if (check != 0) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
					}
					else
						file >> symbol;
					while (i < 3) {
						tex[j].line[i] = symbol;
						i++;
						file >> symbol;
						check = 1;
					}
					j++;
				}
			}
			int vertexes = count();
			int **matrix = new int*[vertexes];
			for (int i = 0;i < vertexes;i++) {
				matrix[i] = new int[vertexes];
			}
			for (int i = 0;i < vertexes;i++)
				for (int j = 0;j < vertexes;j++)
				{
					matrix[i][j] = 0;
				}
			char *formatrix = new char[vertexes];
			int ji = 0;
			for (int f = 0;f < edges;f++) {
				if (checksymbol(formatrix, tex[f].line[0]) == false) {
					formatrix[ji] = tex[f].line[0];
					ji++;
				}
				if (checksymbol(formatrix, tex[f].line[1]) == false) {
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
			int testing = max_flow(matrix, 0, vertexes - 1, vertexes);
			Assert::AreEqual(testing, 0);
			file.close();
		}
	};
}