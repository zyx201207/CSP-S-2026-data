#include <iostream>
#include <cstdio>
using namespace std;
string c1,s1,c2,s2;
bool check()
{
	char op1 = s1[2],op2 = s2[2];
	if(op1=='B'&&(op2=='A'||op2=='C')) return 1;
	if(op2=='B'&&(op1=='A'||op1=='C')) return 1;
	if(op1=='D'&&op2=='F') return 1;
	if(op2=='D'&&op1=='F') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) 
	{
		cout << 1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) 
		{
			cout << 1;
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')
			{
				cout << 1;
				if(check()) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else cout << "00" << endl;
		}
		else cout << "000" << endl;
	}
	else cout << "0000" << endl;
	return 0;
} 
