#include"pch.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<fstream>
#include<cctype>
#include"C:\Users\Alex\source\repos\templist\templist\temp_list.h"

using namespace std;
struct text {// for checking
	char line[10];
	int numb;
};
int min(int x, int y)// find min number
{
	if (x < y)
		return x;
	else
		return y;
}

bool checksymbol(char *array,char symbol) {// check symbol in array
	int n = strlen(array);
	for (int i = 0;i< n;i++) {
		if (array[i] == symbol)
			return true;
	}
	return false;
}
int findindex(char *array, char symbol) {// find an index of symbol in array
	int n = strlen(array);
	if (checksymbol(array, symbol) == false)
		return INT_MAX;
	for (int i = 0;i < n;i++) {
		if (array[i] == symbol)
			return i;
	}
}
int countedge() {// count edges in file
	fstream file;
	int number = 0;
	int edge = 0;
	char symb;
	file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
	while (!file.eof()) {
		number = 0;
		while (number < 3) {
			file >> symb;
			number++;
		}
		edge++;
	}
	return edge-1;
}
bool secondcheck(text *file,int edges) {//second stage of checking
	int i = 0;
	int j = 0;
	int h = 0;
	char test;
	char array[1000];
	for (int i = 0;i < edges;i++) {
		if (j == 0) {
			array[h] = file[i].line[0];
			h++;
			array[h] = file[i].line[1];
			j++;
			h++;
		}
		else
		{
			if (checksymbol(array, file[i].line[0]) == false) {
				cout << "in" << " " << i+1 << " " << "row"<<" " << "first symbol is  uninitialized" << endl;
				return false;
			}
			array[h] = file[i].line[0];
			h++;
			array[h] = file[i].line[1];
			h++;
		}
	}
	return true;
}

int count() { // count number of vertex
	fstream file;
	int vertex = 0;
	int j = 0;
	file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
	char symbol;
	char *array = new char[1000];
	while (!file.eof()) {
		file >> symbol;
		if ((checksymbol(array, symbol) == false)&&((symbol!='1')&& (symbol != '2')&&(symbol != '3')&&(symbol != '4') && (symbol != '5') && (symbol != '6') && (symbol != '7') && (symbol != '8') && (symbol != '9') && (symbol != '0'))) {
			vertex++;
			array[j] = symbol;
			j++;
		}
	}
	return vertex;
	file.close();
}
bool firstcheck() {// first stage of checking
	fstream file;
	char line[3];
	file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
	while (!file.eof()) {
		file >> line[0];
		if (isalpha(line[0]) == false) {
			cout << "error, first symbol has to be a letter" << endl;
			return false;
		}
		file >> line[1];
		if (isalpha(line[1]) == false) {
			cout << "error, second symbol has to be a letter" << endl;
			return false;
		}
		file >> line[2];
		if ((isdigit(line[2]) == false)&&(line[2]=='-')) {
			cout << "capacity has to be Above zero" << endl;
			return false;
		}
		if (isdigit(line[2]) == false) {
			cout << "error, third symbol has to be a digit" << endl;
			return false;
		}
	}
	return true;
}

bool maincheck(text *file,int edges) {// main function od checking. third stage
	if (file[0].line[0] != 'S') {
		cout << "first symbol has to be s" << endl;
		return false;
	}
	if (file[edges-1].line[1] != 'T') {
		cout << "last symbol has to be t" << endl;
		return false;
	}
	if (secondcheck(file, edges) == false)
		return false;
	for (int i = 0;i < edges;i++) {
		if ((int)file[i].line[2] < 0) {
			cout <<"in row"<<i+1<<" "<< "capacity has to be Above zero" << endl;
			return false;
		}
		if (file[i].line[0] == 'T') {
			cout << "t can only be a stock" << endl;
			return false;
		}
		if (file[i].line[1] == 'S'){
			cout<<"s can only be a source"<<endl;
				return false;
		}
	}
	return true;
}

bool BFS(int **matrix, int source,int stock,int *parent,int Vertexes) {// BFS
	bool *visited=new bool[Vertexes];
	memset(visited, 0, Vertexes);
	Lists<int> queue;
	queue.push_back(source);
	visited[source] = true;
	parent[source] = -1;
	while (!queue.isEmpty_()) {
		int u = queue.at(1);
		queue.pop_back();
		for (int i = 0;i < Vertexes;i++){
			if((visited[i]==false&&matrix[u][i]>0)){
				queue.push_back(i);
				parent[i] = u;
				visited[i] = true;
			}

		}
	}
	cout << endl;
	//if(visited[t]==true)
		//cout<<"yes";
	return(visited[stock] == true);
}

int max_flow(int **matrix, int source, int stock, int Vertexes) {// find max flow
	int forparent = 0;
	int v = 0;
	int **rmatrix = new int*[Vertexes];
	for (int i = 0;i < Vertexes;i++) {
		rmatrix[i] = new int[Vertexes];
	}
	for (int i=0; i < Vertexes; i++)
		for (int j = 0; j < Vertexes; j++)
			rmatrix[i][j] = matrix[i][j];
	
	int *parent = new int[Vertexes];
	int maxflow = 0;
	while (BFS(rmatrix, source, stock, parent, Vertexes)) {
		int PathFlow = INT_MAX;
		for (int i = stock;i != source;i = parent[i]) {
			forparent = parent[i];
			PathFlow = min(PathFlow, rmatrix[forparent][i]);
		}
		for (int i = stock;i != source;i = parent[i]) {
			forparent = parent[i];
			rmatrix[forparent][i] = rmatrix[forparent][i] - PathFlow;
			rmatrix[i][forparent] = rmatrix[i][forparent] + PathFlow;
		}
		maxflow = maxflow + PathFlow;
	}
	return maxflow;
}
int main(){
	int Vertexes = count();
	char symbol=' ';
	int edges = countedge();
	int j = 0;
	int **matrix = new int*[Vertexes];
	for (int i = 0;i < Vertexes;i++) {
		matrix[i] = new int[Vertexes];
	}
	text *tex = new text[edges]; // array of structures 
	fstream file;
	int check = 0;
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
			while (i<3) {
				tex[j].line[i] = symbol;
				i++;
				file >> symbol;
				check = 1;
			}
			j++;
		}
	}
	else
		return 0;
	if (maincheck(tex, edges) == false)
		return 0;
	else
		cout << "right data" << endl;
	char *formatrix = new char[Vertexes];
	int finish = 0;
	for (int f = 0;f < edges;f++) {
		if (checksymbol(formatrix, tex[f].line[0]) == false) {
			formatrix[finish] = tex[f].line[0];
			finish++;
		}
		if (checksymbol(formatrix, tex[f].line[1]) == false) {
			formatrix[finish] = tex[f].line[1];
			finish++;
		}
	}
	formatrix[finish] = '\0';
	for (int i = 0;i < Vertexes;i++)
		for (int j = 0;j < Vertexes;j++)
		{
			matrix[i][j] = 0;
		}
	for (int i = 0;i < edges;i++) { // build a matrix
		int x = findindex(formatrix, tex[i].line[0]);
		int y= findindex(formatrix, tex[i].line[1]);
		string help =" ";
		help[0] = tex[i].line[2];
		int index = stoi(help);
		matrix[x][y] = index;
	}
	cout << "matrix:" << endl;
	for (int i = 0;i <= Vertexes-1;i++)
	{
		for (int j = 0;j <= Vertexes-1;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int flow = max_flow(matrix, 0, Vertexes -1, Vertexes);
	cout <<"maximum flow "<< flow;
}










