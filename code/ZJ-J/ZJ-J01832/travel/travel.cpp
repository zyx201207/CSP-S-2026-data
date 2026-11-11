#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char op1,op2;
string a,b;
int h(char ch)
{
	if(ch>='A'&&ch<='C')
	return 1;
	if(ch>='D'&&ch<='F')
	return 2;
}
bool g(char u,char v)
{
	if(u=='A')
	{
		if(v=='B')
		return true;
		else
		return false;
	}
	else if(u=='B')
	{
		if(v=='A'||v=='C')
		return true;
		else
		return false;
	}
	else if(u=='C')
	{
		if(v=='B')
		return true;
		else
		return false;
	}
	else if(u=='D')
	{
		if(v=='F')
		return true;
		else
		return false;
	}
	else if(u=='F')
	{
		if(v=='D')
		return true;
		else
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a+=s1[0]+s1[1];
	b+=s2[0]+s2[1];
	op1=s1[2];
	op2=s2[2];
	if(c1==c2)
	{
		cout<<1;
		if(a==b)
		{
			cout<<1;
			if(h(op1)==h(op2))
			{
				cout<<1;
				if(g(op1,op2))
				cout<<1;
				else
				cout<<0;
			}
			else
			cout<<"00";
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	return 0;
}
