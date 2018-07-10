#include "Stack.h"

void introduction();
void instructions();
char get_command();
bool do_command(string s, Stack &numbers);

int main(){
	string s;
	cout << "请输入逆波兰计算式(最后要有等号):";
	getline(cin, s);
	Stack stored_numbers;
	introduction();
	instructions();
	do_command(s, stored_numbers);
	
}

void introduction()
{

}

void instructions()
{

}

char get_command()										//用于输入字符，但在实现不用输入？=符号时，这个函数用不到
{
	char command;
	bool waiting = true;
	cout << " Select command and press <Enter>:";
	while(waiting)
	{
		cin >> command;
		command = tolower(command);
		if(command == '?' || command == '=' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'q')
			waiting = false;
		else
		{
			cout << "Please enter a valid command:" << endl
				<< "[?]push to stack [=]print top" << endl
				<< "[+][-][*][/] are arithmetic operations" << endl
				<< "[Q]uit" << endl;

		}
	}
	return command;
}

bool do_command(string s, Stack &numbers)
{
	char command;
	double p, q;
	istringstream sin(s);
	sin >> p;
	if (numbers.push(p) == overflow)							//在这个if判断语句里面，是先做numbers.push(p)，不管垢面结果，这个语句已经做了
		cout << "Warning:Stack full, lost number" << endl;
	while (sin >> p)
	{
		if(numbers.push(p) == overflow)
			cout << "Warning:Stack full, lost number" << endl;
		sin >> command;

		switch (command)
		{
		case '?':
			cout << "Enter a real number:" << flush;
			cin >> p;
			if (numbers.push(p) == overflow)
				cout << "Warning:Stack full, lost number" << endl;
			break;
		case '=':
			if (numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
				cout << p << endl;
			break;
		case '-':
			if (numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q - p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
			break;
		case '+':
			if (numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q + p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
			break;
		case '*':
			if (numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q*p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
			break;
		case '/':
			if (numbers.top(p) == underflow)
				cout << "Stack empty" << endl;
			else
			{
				numbers.pop();
				if (numbers.top(q) == underflow)
				{
					cout << "Stack has just one entry" << endl;
					numbers.push(p);
				}
				else
				{
					numbers.pop();
					if (numbers.push(q / p) == overflow)
						cout << "Warning: Stack full, lost result" << endl;
				}
			}
			break;
		case 'q':
			cout << "Ca;culation finished.\n";
			return false;
		}
	}
	if (numbers.top(p) == underflow)
		cout << "Stack empty" << endl;
	else
		cout << p << endl;
	return true;
}