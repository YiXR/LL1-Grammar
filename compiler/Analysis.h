#ifndef _ANALYSIS_H_
#define _ANALYSIS_H_
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>
using namespace std;

struct node
{
	string left;
	string right[100];
};

class Analysis
{
protected:
	int T;
	node analysis_str[100];

	set<string> first_set[100];//first集
	set<string> follow_set[100];//follow集
	vector<string> ter_withoutblack; //去空字终结符
	vector<string> terminal;//终结符
	vector<string> nonterminal;//非终结符

public:
	Analysis() :T(0) {}
	bool isNotTerminal(string c);//判断是否为非终结符
	void remove();//左递归消除
	int get_index(string target);//获得在终结符集合中的下标
	int get_non_index(string target);//获得在非终结符集合中的下标
	void get_first(string target); //得到first集合
	void get_follow(string target);//得到follow集合
	void inputAndSolve(); //处理得到first和follow
	void display(); //显示

};
#endif 
