#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a1,b1,a2,b2;
	char f1,f2;
	
	if(c1[0]=='0')
	{
		a1=c1[1]-'0';
	}
	else
	{
		a1=int(c1[0]-'0')*10+(c1[1]-'0');
	}
	if(c2[0]=='0')
	{
		a2=c2[1]-'0';
	}
	else
	{
		a2=int(c2[0]-'0')*10+(c2[1]-'0');
	}
	
	if(s1[0]=='0')
	{
		b1=s1[1]-'0';
	}
	else
	{
		b1=int(s1[0]-'0')*10+(s1[1]-'0');
	}
	f1=s1[2];
	if(s2[0]=='0')
	{
		b2=s2[1]-'0';
	}
	else
	{
		b2=int(s2[0]-'0')*10+(s2[1]-'0');
	}
	f2=s2[2];
	
	if(a1==a2)
	{
		cout << 1;
		if(b1==b2)
		{
			cout << 1;
			if( ( (f1=='A' || f1=='B' || f1=='C') && (f2=='A' || f2=='B' || f2=='C') ) || ( (f1=='D' || f2=='E') && (f2=='D' || f2=='E') ) )
			{
				cout << 1;
				if(f1==(f2+1) || f1==(f2-1))
				{
					cout << 1;
				}
				else
				{
					cout <<0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
 } 
