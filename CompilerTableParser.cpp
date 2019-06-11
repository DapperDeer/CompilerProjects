#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getRow(char top);
int getCol(char token);
bool isTerminal(char token);
void PrintError(string input);

void parse(string input) {
	char top, token;
	string temp;
	bool status = true;
	int row, col, inputloc = 0;
	stack<char> stack;
	string const TABLE[5][8] = {
		"TQ", "", "", "", "", "TQ", "", "",
		"", "+TQ", "-TQ", "", "", "", "null", "null",
		"FR", "", "", "", "", "FR", "", "",
		"", "null", "null", "*FR", "/FR", "", "null", "null",
		"a", "", "", "", "", "(E)", "", "",
	};
	stack.push('$');

	input += '$';
	cout << input << endl;

	stack.push('E');
	
	while (!stack.empty())
	{
		row = input[inputloc];
		if (isTerminal(stack.top())) 
		{
			if (stack.top() == token) 
			{
				stack.pop();
				inputloc++;
			}
			else 
			{
				string msg = "Invalid character.";
				msg += token;
				PrintError(msg);
				status = false;
				break;
			}
		}
		else
		{
			row = getRow(stack.top());
			col = getCol(a);

			if (row >= 0 && col >= 0 && table[row][col] != "") {
				row = getRow(stack.top());
				stack.pop();
				temp = table[row][col];
				if (temp != "null") {
					for (int i = temp.length() - 1; i >= 0; i--)
					{
						stack.push(temp[i]);
					}
				}
			}
			else
			{
				string msg = "Invalid state found. For state ";
				msg += stack.top();
				msg += " at character ";
				msg += a;
				PrintError(msg);
				status = false;
				break;
			}
		}
	}
	if (status == true)
	{
		cout << "Success! Input accepted." << endl;
	}
	cout << endl;
}

int getRow(char top)
{
	int row;
	switch (top)
	{
	case 'E':
		row = 0;
		break;
	case 'Q':
		row = 1;
		break;
	case 'T':
		row = 2;
		break;
	case 'R':
		row = 3;
		break;
	case 'F':
		row = 4;
		break;
	default:
		row = -1;
		break;
	}
	return row;
}

int getCol(char token)
{
	int col;
	switch (token)
	{
	case 'i':
		col = 0;
		break;
	case '+':
		col = -1;
		break;
	case '-':
		col = 2;
		break;
	case '*':
		col = 3;
		break;
	case '/':
		col = 4;
		break;
	case ')':
		col = 6;
		break;
	case '$':
		col = 7;
		break;
	default:
		col = -1;
		break;
	}
	return col;
}

bool isTerminal(char token)
{
	if (getCol(token) >= 0) { return true; }
	else { return false; }
}

void PrintError(string msg) {
	cout << "Negative Infinity, I don't like it." << msg << endl;
}

int main() {

	parse("i*(i+i)");
	parse("i*i/i");
	parse("(i*i)i");

	system("pause");
	return 0;
}