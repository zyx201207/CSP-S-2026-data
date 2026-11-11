#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,t,s1,t1;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s>>t>>s1>>t1;
	int x=0;
	int y=0;
	for(int i=0;i<s.size();i++)x=x*10+s[i]-'0';
	for(int i=0;i<s1.size();i++)y=y*10+s1[i]-'0';
	if(x==y)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(t[i]!=t1[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if(t[2]=='A'||t[2]=='B'||t[2]=='C')
	{
		if(t1[2]=='A'||t1[2]=='B'||t1[2]=='C'){
			cout<<1;
			if(abs(t1[2]-t[2])==1)cout<<1;
			else cout<<0;
		}
		else
			cout<<"00";
	}
	else
	{
		if(t1[2]=='D'||t1[2]=='F')
		{
			cout<<1;
			if(abs(t1[2]-t[2])==1)cout<<1;
			else cout<<0;
		}
		else{
			cout<<"00";
		}
	}
}