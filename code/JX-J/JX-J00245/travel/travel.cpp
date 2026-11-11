#include <bits/stdc++.h>
using namespace std;
bool pd(char x,char y)
{
	if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')) return 1;
	if((x=='D'||x=='F')&&(y=='D'||y=='F')) return 1;
	return 0;
}
bool pd2(char x,char y)
{
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')) return 1;
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='C'&&y=='B')) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2;
	cin>>s1>>a1>>s2>>a2;
	if(s1==s2)
	{
		cout<<1;
		if(a1[0]==a2[0]&&a1[1]==a2[1]) 
		{
			cout<<1;
			if(pd(a1[2],a2[2]))
			{
				cout<<1;
				if(pd2(a1[2],a2[2])) cout<<1;
				else 
				{
					cout<<0;
				}
			}
			else 
			{
				cout<<0;
				cout<<0;
			}
		}
		else 
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else 
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
