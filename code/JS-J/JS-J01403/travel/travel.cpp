#include<bits/stdc++.h>
using namespace std;
string A,B,C,D;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>B>>C>>D;
	if(A==C)
	{
		cout<<'1';
		if(B[0]==D[0]&&B[1]==D[1])
		{
			cout<<'1';
			if((B[2]=='D'&&D[2]=='F')||(B[2]=='F'&&D[2]=='D')||(B[2]=='A'&&D[2]=='B')||(B[2]=='B'&&D[2]=='A')||(B[2]=='B'&&D[2]=='C')||(B[2]=='C'&&D[2]=='B')||(B[2]=='A'&&D[2]=='C')||(B[2]=='C'&&D[2]=='A'))
			{
				cout<<'1';
				if((B[2]=='D'&&D[2]=='F')||(B[2]=='F'&&D[2]=='D')||(B[2]=='A'&&D[2]=='B')||(B[2]=='B'&&D[2]=='A')||(B[2]=='B'&&D[2]=='C')||(B[2]=='C'&&D[2]=='B'))
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<'0'<<'0';
			}
		}
		else
		{
			cout<<'0'<<'0'<<'0';
		}
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	return 0;
}
