#include "stdafx.h"
#include "SymbolTable.h"
#include <algorithm>
#include <list>

using namespace std;

#pragma region SymbolTable Functions

SymbolTable::SymbolTable()
{
	this->stackAddress = 2000;

}

SymbolTable::SymbolTable(vector<string> symId, list<string> lexemes)
{
	this->stackAddress = 2000;
	this->symId = symId;
	this->lexemes = lexemes;
	createSymbolTable();
	removeInt();
	removeBool();


}

void SymbolTable::removeBool()
{
	string type = "boolean";

	list<string>::iterator it;

	for (int i = 0; i < this->lexemes.size(); i++)
	{

		it = find(this->lexemes.begin(), this->lexemes.end(), type);

		if (it != this->lexemes.end())
		{
			list<string>::iterator end;

			end = find(this->lexemes.begin(), this->lexemes.end(), ";");

			if(end != this->lexemes.end())
				lexemes.erase(it, ++end);

		}

	}


}

void SymbolTable::removeInt()
{
	string type = "int";

	list<string>::iterator it;

	for (int i = 0; i < this->lexemes.size(); i++)
	{
		it = find(this->lexemes.begin(), this->lexemes.end(), type);

		if (it != this->lexemes.end())
		{
			list<string>::iterator end;

			end = find(this->lexemes.begin(), this->lexemes.end(), ";");

			lexemes.erase(it, ++end);

		}

	}

}

void SymbolTable::createSymbolTable()
{

	symTableInput input;
	string type;

	for (int i = 0; i < symId.size(); i++)
	{
		if (symId[i] == "int")
		{
			type = "integer";
			input.id = "";
			

		}
		else if (symId[i] == "boolean")
		{
			type = "boolean";
			input.id = "";
			
		}
		else
		{
			input.id = symId[i];
		}
		
		
		if (input.id != "")
		{
			input.memAddrs = this->stackAddress;
			input.type = type;
			symbolTable.push_back(input);
			stackAddress++;
		}
		
		
		

	}
	

}

void SymbolTable::printSymbolTable()
{
	symTableInput input;
	for (int i = 0; i < symbolTable.size(); i++)
	{
		input = symbolTable[i];
		cout << input.id << "\t" << input.memAddrs << "\t" << input.type << endl;

	}

}

#pragma endregion

#pragma region

int SymbolTable::getAddress(string input)
{	
	int i = 0;
	int address = -1;

	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].id == input)
		{
			address = symbolTable[i].memAddrs;
			return address;
		}

	}

	return address;

	/*while (symbolTable[i].id != input && i < symbolTable.size())
	{
		i++;
	}
	if (i == symbolTable.size() - 1)
	{
		if (symbolTable[i].id == input)
		{
			address = symbolTable[i].memAddrs;
			return address;
		}
		else
			return address; //note here address is -1 for error checking
	}
	else
	{
		address = symbolTable[i].memAddrs;
		return address;


	}*/

}

#pragma endregion

SymbolTable::~SymbolTable()
{
}
