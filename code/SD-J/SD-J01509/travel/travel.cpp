#include<bits/stdc++.h>
using namespace std;
int f(char s)
{
	int ans;
	if(s=='A') ans='A';
	else if(s=='B') ans='B';
	else if(s=='C') ans='C';
	else if(s=='D') ans='D'+1;
	else if(s=='F') ans='F';
	return ans;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int r=0,x=0;
	for(int i=0;i<c1.size();i++)
	{
		if(isdigit(c1[i])) r=r*10+c1[i]-'0';
	} 
	for(int i=0;i<c2.size();i++)
	{
		if(isdigit(c2[i])) x=x*10+c2[i]-'0';
	} 
	if(r!=x)
	{
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	int a=0,b=0,m,n;
	for(int i=0;i<s1.size();i++)
	{
		if(isdigit(s1[i])) a=a*10+s1[i]-'0';
		else m=f(s1[i]);
	} 
	for(int i=0;i<s2.size();i++)
	{
		if(isdigit(s2[i])) b=b*10+s2[i]-'0';
		else n=f(s2[i]);
	} 	
	if(a!=b)
	{
		cout<<"000";
		return 0;
	}
	else cout<<1;
	if(m>='E'&&n>='E'||m<'E'&&n<'E') cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abs(m-n)!=1)cout<<0;
	else cout<<1;
	return 0;
}

