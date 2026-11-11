#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int c,t,n,d,x[5010];
vector<pair<int,int> > ve[2500010];
vector<int> v1,v2;
bool vis[5010];
int dis[5010];
int mi=2e7;
void s1(int u,int t)
{
	v1.push_back(u);
	for(auto v:ve[u])
	{
		if(dis[v.first]>dis[u]+v.second)
		{
			dis[v.first]=dis[u]+v.second;
			vis[v.first]=1;
			s1(v.first,t);
		}
	}
}
void s2(int u,int t)
{
	v2.push_back(u);
	for(auto v:ve[u])
	{
		if(dis[v.first]>dis[u]+v.second&&!vis[v.first])
		{
			dis[v.first]=dis[u]+v.second;
			vis[v.first]=1;
			s2(v.first,t);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++)
		{
			for(int j=j+1;j<=n;j++)
			{
				if(i==j) continue;
				if(abs(x[i]-x[j])<=d) 
				{
					ve[i].push_back({j,abs(x[i]-x[j])});
				}
			}
		}
		int cnt=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				v1.clear();
				v2.clear();
				s1(i,j);
				s2(i,j);
				if((int)v1.size()==(int)v2.size()) 
				{
					bool f=0;
					for(int i=0;i<v1.size();i++) if(v1[i]==v2[i]) f=1;
					if(f==0) cnt++;
				}
				for(int k=i;k<=j;k++) vis[k]=0;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;	
} 
