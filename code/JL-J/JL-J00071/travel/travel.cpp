#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	bool flag = 1;
	cin >> a >> b >> c >> d;
	if(a == c)	cout << "1";
	else	
	{	
		cout << "0"; 
		flag = 0;
	}
	for(int i = 0; i < 2; i++)
	{
		if(flag == 0)
		{
			cout << "0";
			break;
		}
		else {
			if(b[i] != d[i])
			{
				cout << "0";
				flag = 0;
				break;
			}
		}
	}
	if(flag) 
		cout << "1";
	if(flag == 0) cout << "0";
	if(b[2] == 'C' && d[2] == 'D' && flag == 1)
	{
		cout << "0";
		flag = 0;
	}
	if(d[2] == 'C' && b[2] == 'D' && flag == 1)
	{
		cout << "0";
		flag = 0;
	}
	if(flag == 1) cout << "1";
	if(!flag) cout << "0";
	else
	{
		if(b[2] - d[2] == 1) cout << "1";
		else if(d[2] - b[2] == 1) cout << "1";
		else
		cout << "0";
	}
	return 0;
}
