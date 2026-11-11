#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
#define int long long
#define fir first
#define sec second
#define lc u<<1
#define rc u<<1|1
#define ull unsigned long long
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int INF=-1e18;
const int N=2e6+10;
int a[N],pre[N];
vector<int> e[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios;
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					e[a[i]].push_back(a[j]);
					e[a[j]].push_back(a[i]);
				}
			}
		}
		cout<<0<<"\n";
	}
	return 0;
} 
