#include<bits/stdc++.h>
using namespace std;
long long int i;
string s1,c1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F')
	s1[2]+=1;
	if(s2[2]=='F')
	s2[2]+=1;
	if(s1[2]=='D')
	s1[2]+=2;
	if(s2[2]=='D')
	s2[2]+=2;
	//1
	if(c1==c2)
	cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	//2
	for(i=0;i<2;i++)
	if(s1[i]!=s2[i])
	{
		cout<<0<<0<<0;
		return 0;
	}
	cout<<1;
	//3
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2]||s1[2]-1==s2[2]||s2[2]-1==s1[2]||s1[2]+2==s2[2]||s2[2]+2==s1[2])
	cout<<1;
	else
	{
		cout<<0<<0;
		return 0;
	}
	//4
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='F'&&s2[2]=='G')
	{
		cout<<1;
		return 0;
	}
	if(s2[2]=='A'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='C'||s2[2]=='F'&&s1[2]=='G')
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}