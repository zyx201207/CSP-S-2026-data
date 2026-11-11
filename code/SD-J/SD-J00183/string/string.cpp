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
const int N=2e5+10;
const int INF=1e18;
int a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios;
	string s;
	s+=" ";
	int n,L=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		L+=a;
		for(int i=1;i<=a;i++) s+=c;
	}
	int ans=0;
	for(int i=1;i<=L;i++)
	{
		if(s[i]!=s[L+1-i])
		{
			s[i]=s[L+1-i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
