#include "Stack.h"

void introduction();
void instructions();
char get_command();
bool do_command(string s, Stack &numbers);

int main(){
	string s;
	cout << "�������沨������ʽ(���Ҫ�еȺ�):";
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

char get_command()										//���������ַ�������ʵ�ֲ������룿=����ʱ����������ò���
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
	if (numbers.push(p) == overflow)							//�����if�ж�������棬������numbers.push(p)�����ܹ��������������Ѿ�����
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