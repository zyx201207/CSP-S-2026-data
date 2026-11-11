#include<bits/stdc++.h>
using namespace std;

string a,b;
int a2;
string a1;
int b2;
string b1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a >> a1 >> b >> b1;
	a1 = " " + a1;
	b1 = " " + b1;
	if(a1[1] > '0') a2 += (a1[1] - '0') * 10;
	if(a1[2] >= '0' && a1[2]<= '9') a2 += (a1[2] - '0');
	if(b1[1] > '0') b2 += (b1[1] - '0') * 10;
	if(b1[2] >= '0' && b1[2]<= '9') b2 += (b1[2] - '0');
	
	for(int i = 1;i <= 4;i ++)
	{
		if(i == 1)
		{
			if(a == b)
			{
				cout << 1;
				continue;
			}
			else
			{
				cout << "0000";
				return 0;
			}
		}
		else if(i == 2)
		{
			if(a2 == b2)
			{
				cout << 1;
				continue;
			}
			else{
				cout << "000";
				return 0;
			}
		}
		else if(i == 3)
		{
			if(a1[3] == 'A' && b1[3] == 'B')
			{
				cout << 1;
				continue;
			}
			else if((a1[3] == 'B' && b1[3] == 'A')||(a1[3] == 'B' && b1[3] == 'C'))
			{
				cout << 1;
				continue;
			}
			else if((a1[3] == 'C' && b1[3] == 'B') ||(a1[3]=='C' && b1[3] == 'A'))
			{
				cout << 1;
				continue;
			}
			else if(a1[3] == 'D' && b1[3] == 'F')
			{
				cout << 1;
				continue;
			}
			else if(a1[3] == 'F' && b1[3] == 'D')
			{
				cout << 1;
				continue;
			}
			else
			{
				cout << "00";
				return 0;
			}
		}
		else if(i == 4)
		{
			if(a1[3] == 'A' && b1[3] == 'B')
			{
				cout << 1;
				return 0;
			}
			else if((a1[3] == 'B' && b1[3] == 'A')||(a1[3] == 'B' && b1[3] == 'C'))
			{
				cout << 1;
				return 0;
			}
			else if(a1[3] == 'C' && b1[3] == 'B') 
			{
				cout << 1;
				return 0;
			}
			else if(a1[3] == 'D' && b1[3] == 'F')
			{
				cout << 1;
				return 0;
			}
			else if(a1[3] == 'F' && b1[3] == 'D')
			{
				cout << 1;
				return 0;
			}
			else
			{
				cout << "0";
				return 0;
			}
		}
	}
	return 0;
}
