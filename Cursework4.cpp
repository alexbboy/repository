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
	int i = 0;
	int edge = 0;
	char symb;
	file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
	while (!file.eof()) {
		i = 0;
		while (i < 3) {
			file >> symb;
			i++;
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
	char symb[1000];
	for (int i = 0;i < edges;i++) {
		if (j == 0) {
			symb[h] = file[i].line[0];
			h++;
			symb[h] = file[i].line[1];
			j++;
			h++;
		}
		else
		{
			if (checksymbol(symb, file[i].line[0]) == false) {
				cout << "in" << " " << i+1 << " " << "row"<<" " << "first symbol is  uninitialized" << endl;
				return false;
			}
			symb[h] = file[i].line[0];
			h++;
			symb[h] = file[i].line[1];
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
	char per;
	char *symb = new char[1000];
	while (!file.eof()) {
		file >> per;
		if ((checksymbol(symb, per) == false)&&((per!='1')&& (per != '2')&&(per != '3')&&(per != '4') && (per != '5') && (per != '6') && (per != '7') && (per != '8') && (per != '9') && (per != '0'))) {
			vertex++;
			symb[j] = per;
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

bool BFS(int **matrix, int s,int t,int *parent,int V) {// BFS
	bool *visited=new bool[V];
	memset(visited, 0, V);
	Lists<int> q;
	q.push_back(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.isEmpty_()) {
		int u = q.at(1);
		q.pop_back();
		for (int i = 0;i < V;i++){
			if((visited[i]==false&&matrix[u][i]>0)){
				q.push_back(i);
				parent[i] = u;
				visited[i] = true;
			}

		}
	}
	cout << endl;
	//if(visited[t]==true)
		//cout<<"yes";
	return(visited[t] == true);
}

int max_flow(int **matrix, int s, int t, int V) {// find max flow
	int u = 0;
	int v = 0;
	int **rmatrix = new int*[V];
	for (int i = 0;i < V;i++) {
		rmatrix[i] = new int[V];
	}
	for (int i=0; i < V; i++)
		for (int j = 0; j < V; j++)
			rmatrix[i][j] = matrix[i][j];
	
	int *parent = new int[V];
	int maxflow = 0;
	while (BFS(rmatrix, s, t, parent, V)) {
		int PathFlow = INT_MAX;
		for (int i = t;i != s;i = parent[i]) {
			u = parent[i];
			PathFlow = min(PathFlow, rmatrix[u][i]);
		}
		for (int i = t;i != s;i = parent[i]) {
			u = parent[i];
			rmatrix[u][i] = rmatrix[u][i] - PathFlow;
			rmatrix[i][u] = rmatrix[i][u] + PathFlow;
		}
		maxflow = maxflow + PathFlow;
	}
	return maxflow;
}
int main(){
	int tops = count();
	char symb=' ';
	int edges = countedge();
	int j = 0;
	int **matrix = new int*[tops];
	for (int i = 0;i < tops;i++) {
		matrix[i] = new int[tops];
	}
	text *tex = new text[edges]; // array of structures 
	fstream file;
	int check = 0;
	file.open("C:\\Users\\Alex\\Desktop\\curse.txt", ios::in);
	if (firstcheck() == true) {
		while (!file.eof()) {
			int i = 0;
			if (check != 0) {
				tex[j].line[i] = symb;
				i++;
				file >> symb;
			}
			else
				file >> symb;
			while (i<3) {
				tex[j].line[i] = symb;
				i++;
				file >> symb;
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
	char *formatrix = new char[tops];
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
	for (int i = 0;i < tops;i++)
		for (int j = 0;j < tops;j++)
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
	for (int i = 0;i <= tops-1;i++)
	{
		for (int j = 0;j <= tops-1;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int flow = max_flow(matrix, 0, tops -1, tops);
	cout <<"maximum flow "<< flow;
}










