#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,q,w,q1,w1;
	string s1,s2;
	char e,e1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size()-2;i++)
	{
		q=s1[i];
	}
	for(int i=1;i<s1.size()-1;i++)
	{
		w=s1[i];
	}
	for(int i=1;i<s1.size();i++)
	{
		e=s1[i];
	}
	for(int i=0;i<s2.size()-2;i++)
	{
		q1=s2[i];
	}
	for(int i=1;i<s2.size()-1;i++)
	{
		w1=s2[i];
	}
	for(int i=1;i<s2.size();i++)
	{
		e1=s2[i];
	}
	if(q==q1 && w==w1)
		cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((e>='A' && e<='C') && (e1<='C' && e1>='A'))
		cout<<1;
	else if((e<='F' && e>='D') && (e1<='F' && e1>='D'))
	{
		cout<<11;
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(e+1==e1 || e==e1+1)
		cout<<1;
	else
		cout<<"0";
	return 0;
 } 
