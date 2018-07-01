#ifndef _TABLESTACK_H_
#define _TABLESTACK_H_

#include"Analysis.h"

class TableStack :public Analysis
{
protected:
	int tableMap[100][100];//预测表
public:
	TableStack() { memset(tableMap, -1, sizeof(tableMap)); }
	void get_table(); //得到预测表
	void print_out();//输出
	void manage(); //综合
};
#endif
