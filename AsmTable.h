#pragma once

#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <list>
#include "SymbolTable.h"

using std::stack;
using std::queue;
using std::string;
using std::vector;
using std::unordered_map;
using std::ofstream;
using std::list;

struct asmTableInput
{
	int line;
	string action;
	int address;

};

class AsmTable
{
public:

	int lineNum;
	//vector<string> semantics = { "TYPE", "PUSHI", "PUSHM", "POPM", "STDOUT", "STDIN", "ADD", "SUB", "MUL", "DIV", "GRT", "LES", "EQU", "NEQ", "GEQ", "LEQ", "JUMPZ", "JUMP", "LABEL" };
	//list<string>::iterator line;
	SymbolTable sm;
	vector<asmTableInput> asmTable;

	stack<int> jmpstack;
	queue<int> jmpQ;
	list<string> lexemes;

	//asmTable
	AsmTable();
	AsmTable(SymbolTable sm);
	void makeAsmTable();

	list<string> getLine(string c);
	list<string> getLine(list<string> line, string c);
	list<string> getLine(string first, string last);
	asmTableInput getTableInput(int line, string action, int address);


	list<string> getLastDelimiter(list<string> line, string delim, int *count);
	bool isSeparetor(string ch);

	void Assign(list<string> line);
	queue<string> Expression(list<string> line);
	queue<string> RelopExpression(list<string> line);
	void If(list<string> line);
	void While(list<string> line);
	void Put(list<string> line);
	void Get(list<string> line);

	void printTable();
	void fillTable(queue<string> result);







	~AsmTable();
};

