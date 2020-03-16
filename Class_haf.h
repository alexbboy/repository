#pragma once
#pragma once
#include"C:\Users\Alex\source\repos\RBtree2\RBtree2\RBtree.h"
#include"C:\Users\Alex\source\repos\templist\templist\temp_list.h"
#include<iomanip>
#include<iostream>
#include<string>
class code {
public:
	friend class red_black<char>;
	friend class red_black<string>;
	friend class Lists<char>;
	red_black<char> tre;
	red_black<string> tre2;
	Lists <trenode<char>> nod;
	Lists <trenode<char>> nod2;
	Lists <trenode<char>> nod4;
	void count(string str, int counting[255]);// 	number of repetitions of letters
	void print(string str, int counting[255], string &save, int save1[255]);//print a tablet
	bool check(string str, char symb, int j); 
	void tree(string str, int count[255]); // build a queye of tre elements
	void coding(node<trenode<char>> *Head, int count[255]); //build a tree
	string sort(string str, int counting[255]); //sort of string
	void get(trenode<char> *nod3); // make a list of leaves
	void code_main(node<trenode<char>> *Head); //made a code of symbols
	string reverse(string str); // reverse string
	void get2(trenode<char> *nod3); //made a list of all elements of tree
	void parrent(node<trenode<char>> *Head); // fix parents
	void parrent2(node<trenode<char>> *Head, int i); // also fix parents
	void print2(trenode<string> *Head, string str); // print final tablet
	string finals(trenode<string> *Head, string str); // make final string 
	void sorting(node<trenode<char>> *Head); // sort of list
};
void code::parrent2(node<trenode<char>> *Head, int i) {
	
	node<trenode<char>> *save = Head;
	while (save != NULL) {
		if (save->data.left != NULL) {
			save->data.left->parent = new trenode<char>;
			save->data.left->parent = &save->data;
		}
		if (save->data.right != NULL) {
			save->data.right->parent = new trenode<char>;
			save->data.right->parent = &save->data;
		}
		save = save->next;
	}
	if (i = 0) {
		nod4.reverse();
		parrent2(nod4.Head, 1);
	}
}
void code::parrent(node<trenode<char>> *Head) {
	node<trenode<char>> *save = Head;
	node<trenode<char>> *save3 = Head;

	while (save != NULL) {
		trenode<char> *savetre = save->data.parent;
		node<trenode<char>> *save2 = Head;
		while (save2 != NULL) {
			if (savetre == NULL)
				break;
			if(save2->data.left!=NULL)
			if (((save2->data.data.data == savetre->data.data) && (save2->data.data.key == savetre->data.key))&&(((save2->data.left->data.data == savetre->left->data.data) && (save2->data.left->data.key == savetre->left->data.key))) && ((save2->data.right->data.data == savetre->right->data.data) && (save2->data.right->data.key == savetre->right->data.key))) {
				save->data.parent = &save2->data;
				break;
			}
			save2 = save2->next;
		}
		save = save->next;
	}
	
}
void code::code_main(node<trenode<char>> *Head) {
	get(&Head->data);
	node<trenode<char>> *save = nod2.Head;
	trenode<char> *savetree = &nod.Head->data;
	while (save != NULL) {
		int i = 0;
		 char *help1=new  char[20] ;
		trenode<char> *savetre2 = &save->data;
		while (savetre2 != &nod.Head->data) {
			if (savetre2->parent == NULL)
				break;
			if(savetre2->parent->left!=NULL)
			if ((savetre2->parent->left->data.data == savetre2->data.data)&& (savetre2->parent->left->data.key == savetre2->data.key)&&(savetre2->parent->left->left==savetre2->left))
				help1[i] = '1';
			if (savetre2->parent->right != NULL)
			if ((savetre2->parent->right->data.data == savetre2->data.data) && (savetre2->parent->right->data.key == savetre2->data.key)&& (savetre2->parent->right->right == savetre2->right))
				help1[i] = '0';
			i++;
			savetre2 = savetre2->parent;
		}
		help1[i] = '\0';
		string help = (string)help1;
		string help2 = " ";
		help2[0] = save->data.data.data;
		help=reverse(help);
		tre2.insert(tre2.Head, help, help2);
		save = save->next;
	}
}
string code::reverse(string str)
{
	char temp;
	int len;
	int i;

	len = str.length() - 1;

	for (i = 0; i <= len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}

	str[len + 1] = '\0';
	return str;
}
void code::get(trenode<char> *nod3) {
	if (nod3 == nullptr) {
		return;
	}

	get(nod3->left);
	if (nod3->data.data != '&')
		nod2.push_back(*nod3);
	get(nod3->right);

}

void code::get2(trenode<char> *nod3) {
	if (nod3 == nullptr) {
		return;
	}

	get2(nod3->left);
		nod4.push_back(*nod3);
	get2(nod3->right);

}

int sum(int count[255]) {
	int weight = sizeof(count);
	int sum = 0;
	for (int i = 0;i < weight;i++) {
		sum = sum + count[i];
	}
	return sum;
}
int numb(node<trenode<char>> *Head) {
	node<trenode<char>> *save = Head;
	int i = 0;
	while (save->next != NULL) {
		save = save->next;
		i++;
	}
	return i;
}
void code::coding(node<trenode<char>> *Head, int count[255]) {
	trenode<char> *save1=new trenode<char>;
	trenode<char> *save2=new trenode<char>;
	node <trenode<char>> *save23 = new node <trenode<char>>;
	node <trenode<char>> *save24 = new node <trenode<char>>;
	int i = 0;
	int summ = sum(count);
	int saving = 0;
	int g = 0;
	int nummb = numb(Head);
	while (nod.get_size() != 1) {
		save23 = Head;
		save24 = Head;
		if(save24->next->next!=NULL)
		while (save24->next->next->next != NULL) {
			save24 = save24->next;
		}
		while (save23->next->next != NULL) {
			save23 = save23->next;
		}
		node <trenode<char>> *save = save23;
		int j = 0;
		node <trenode<char>> *save4 = save23->next;
		trenode<char> *newnode = new trenode<char>;
		newnode->left = new trenode<char>;
		newnode->right = new trenode<char>;
		*newnode->left = save->data;
		*newnode->right = save4->data;
		newnode->left->parent = new trenode<char>;
		newnode->left->parent = newnode;
		newnode->right->parent = new trenode<char>;
		newnode->right->parent = newnode;
		newnode->data.data = '&';
		newnode->data.key = save->data.data.key + save4->data.data.key;
		if ((nod.get_size() == 2)&&(i!=0)) {
			if (nod.Head->next != NULL) {
				if(nod.Head->next->data.right!=NULL)
				nod.Head->next->data.right->parent = &nod.Head->next->data;
				if (nod.Head->next->data.left != NULL)
				nod.Head->next->data.left->parent = &nod.Head->next->data;
			}
			if(nod.Head->data.left!=NULL)
			nod.Head->data.left->parent = &nod.Head->data;
			if (nod.Head->data.right != NULL)
			nod.Head->data.right->parent = &nod.Head->data;
			if(nod.Head->data.right!=NULL)
			if (nod.Head->data.right->left != NULL) {
				nod.Head->data.right->left->parent = nod.Head->data.right;
			}
			if (nod.Head->data.right != NULL)
			if (nod.Head->data.right->left != NULL) {
				nod.Head->data.right->left->parent = nod.Head->data.right;
			}
			if(nod.Head->next->data.right!=NULL)
			if (nod.Head->next->data.right->left != NULL) {
				nod.Head->next->data.right->left->parent = nod.Head->next->data.right;
			}
			if (nod.Head->next->data.right != NULL)
			if (nod.Head->next->data.right->left != NULL) {
				nod.Head->next->data.right->left->parent = nod.Head->next->data.right;
			}
			if (nod.Head->next->data.right->left != NULL)
			if (nod.Head->next->data.right->left->left != NULL) {
				nod.Head->next->data.right->left->left->parent = nod.Head->next->data.right->left;
			}
			if (nod.Head->next->data.right->left != NULL)
			if (nod.Head->next->data.right->left->right != NULL) {
				nod.Head->next->data.right->left->right->parent = nod.Head->next->data.right->left;
			}
			if (nod.Head->data.right->right != NULL) {
				nod.Head->data.right->right->parent = nod.Head->data.right;
			}
			if (nod.Head->data.left->left != NULL) {
				nod.Head->data.left->left->parent = nod.Head->data.left;
			}
			if (nod.Head->data.left->right != NULL) {
				nod.Head->data.left->right->parent = nod.Head->data.left;
			}
		}
		nod.pop_back();
		nod.pop_back();
		nod.push_back(*newnode);
		sorting(nod.Head);
		i++;
	}

	nod.Head->data.parent = new trenode<char>;
	nod.Head->data.parent = NULL;
	nod.Head->data.left->parent = new trenode<char>;
	*nod.Head->data.left->parent = nod.Head->data;
	get2(&nod.Head->data);
	//nod4.Head->data.parent = NULL;
	//nod4.reverse();
	parrent2(nod4.Head, 0);
	parrent(nod4.Head);
	//parrent2(nod4.Head, 0);

}

void code::tree(string str, int counting[255]) {
	for (int i = 0;i < str.length();i++) {
		tre.insert(tre.Head, str[i], (char)counting[i]);
		trenode<char> *save = tre.Head;
		//save->left = new trenode<char>;
		//save->right = new trenode<char>;
		nod.push_back(*save);
		tre.remove(tre.Head, (char)counting[i]);
	}
}
string code::sort(string str, int counting[255]) {
	int max = 0;
	char save = ' ';
	int save1 = 0;
	for (int i = 0;i < str.length();i++) {
		for (int j = 0;j < str.length();j++) {
			if (counting[j] < counting[j + 1]) {
				save = str[j + 1];
				save1 = counting[j + 1];
				counting[j + 1] = counting[j];
				str[j + 1] = str[j];
				str[j] = save;
				counting[j] = save1;
			}
		}
	}
	return str;
}
void code::count(string str, int counting[255]) {
	for (int i = 0;i < str.length();i++) {
		for (int j = 0;j < str.length();j++) {
			if (str[j] == str[i])
				counting[i]++;
		}
	}
}
bool code::check(string str, char symb, int j) {
	for (int i = 0;i < j;i++) {
		if (str[i] == symb)
			return true;
	}
	return false;
}
string convert(char *str) {
	return string(str);
}
void code::print(string str, int counting[255], string &save2, int save1[255]) {
	char *save = new char[255];
	int j = 0;
	for (int i = 0;i < str.length();i++) {
		save[i] = '0';
	}
	for (int i = 0;i < str.length();i++) {
		if (check(str, str[i], i) == false) {
			cout << str[i] << " " << "-" << " " << counting[i] << endl;
			save[j] = str[i];
			save1[j] = counting[i];
			j++;
		}
	}
	save[j] = '\0';
	save2 = string(save);
}
void code::print2(trenode<string> *Head,string str) {
	char *save = new char[255];
	int j = 0;
	for (int i = 0;i < str.length();i++) {
		save[i] = '0';
	}
	while (j<str.length()) {
		string help = " ";
		help[0] = str[j];
		trenode<string> *save = tre2.find(tre2.Head, help);
		cout << save->data.key << " " << "-" << " " << save->data.data << endl;
		j++;
}
}
string code::finals(trenode<string> *Head, string str) {
	string strhelp = "";
	int j = 0;
	while (j < str.length()) {
		char help = str[j];
		string help1 = " ";
		help1[0] = help;
		trenode<string> *save = tre2.find(Head, help1);
		strhelp = strhelp+save->data.data;
		j++;
	}
	return strhelp;
}

void code::sorting(node<trenode<char>> *Head) {
	node<trenode<char>> *left = Head;
	node<trenode<char>> *right = Head->next;

	node<trenode<char>> *temp = new node<trenode<char>>;

	while (left->next) {
		while (right) {
			if ((left->data.data.key) < (right->data.data.key)) {
				temp->data = left->data;
				temp->next = left->next;
				left->data = right->data;
				right->data = temp->data;
				//right->next = temp->next;
				node<trenode<char>> *leftsave = right;
				if (left->data.left != NULL)
					left->data.left->parent = &left->data;
				if (left->data.right != NULL)
					left->data.right->parent = &left->data;
				//left->next = right;
			}
			right = right->next;
		}

		left = left->next;
		right = left->next;
	}
}