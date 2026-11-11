#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lc u>>1
#define rc u>>1+1
#define fir first
#define sec second
string c1,s1,c2,s2;
bool pd()
{
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') return 1;
	}
	if(s1[2]=='D'||s1[2]=='F')
	{
		if(s1[2]=='D'||s1[2]=='F') return 1;
	}
	return 0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(pd())
			{
				cout<<1;
				if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
