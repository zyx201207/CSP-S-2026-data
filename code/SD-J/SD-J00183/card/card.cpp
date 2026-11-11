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
const int N=5e3+10;
const int INF=1e18;
int a[N];
set<int> s;
vector<int> e[N];
bool fd(int i,int k)
{
	for(auto j:e[i])
	{
		if(j==k) return 1;
	}
	return 0;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) e[i].clear();
		s.clear();
		for(int j=i;j<=n;j++)
		{
			int k=a[j];
			if(!fd(i,k)) e[i].push_back(k);
			else
			{
				while(e[i].size()&&e[i].back()!=k)
				{
					e[i].pop_back();
				}
			}
		}
	}
	for(int p=1;p<=m;p++)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			bool f=0;
			for(auto j:e[i])
			{
				if(j==p)
				{
					f=1;
					break;
				}
			}
			if(f) tot++;
		}
		cout<<tot<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1*/
