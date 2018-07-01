#include"TableStack.h"

void TableStack::get_table()
{
	for (int i = 0; i < T; i++)
	{
		string tmp = analysis_str[i].right[0];
		if (!isNotTerminal(tmp))
		{
			if (tmp != "#")
				tableMap[get_index(analysis_str[i].left)][get_non_index(tmp)] = i;
			if (tmp == "#")
			{
				set<string>::iterator  it;
				for (it = follow_set[get_index(analysis_str[i].left)].begin(); it != follow_set[get_index(analysis_str[i].left)].end(); it++)
				{
					tableMap[get_index(analysis_str[i].left)][get_non_index(*it)] = i;
				}
			}
		}
		else
		{
			set<string>::iterator ti;
			for (ti = first_set[get_index(tmp)].begin(); ti != first_set[get_index(tmp)].end(); ti++)
			{
				tableMap[get_index(analysis_str[i].left)][get_non_index(*ti)] = i;
			}
			if (first_set[get_index(tmp)].count("#") != 0)
			{
				set<string>::iterator  it;
				for (it = follow_set[get_index(analysis_str[i].left)].begin(); it != follow_set[get_index(analysis_str[i].left)].end(); it++)
				{
					tableMap[get_index(analysis_str[i].left)][get_non_index(*it)] = i;
				}
			}
		}
	}
}

void TableStack::print_out()
{
	ofstream Out("Table_Output.txt");
	Out << setw(10) << '\0';
	for (int i = 0; i < ter_withoutblack.size(); i++)
	{
		string tercopy;
		tercopy += "  ";
		tercopy += ter_withoutblack[i];
		Out << left << setw(15) << tercopy;
	}
	Out << endl;
	for (int i = 0; i < nonterminal.size(); i++)
	{
		string nonter;
		nonter = nonterminal[i] + ": ";
		Out << setw(10) << nonter;
		for (int j = 0; j < ter_withoutblack.size(); j++)
		{
			if (tableMap[i][j] == -1)
				Out << setw(15) << '\0';
			else
			{
				int k = 0;
				string ss;
				ss += nonterminal[i];
				ss += "->";
				while (analysis_str[tableMap[i][j]].right[k] != "")
				{
					ss += analysis_str[tableMap[i][j]].right[k];
					k++;
				}
				Out << left << setw(15) << ss;
			}
		}
		Out << endl;
	}
	Out.close();
}

void TableStack::manage()
{
	inputAndSolve();
	display();
	get_table();
	print_out();
	return;
}