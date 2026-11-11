#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<debug:<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=5e5+10;
const int M=3e5+10;
/*====================*/
int n,m;
int a[N],sum[N];
bool vis[N];
vector<int>v[N];
/*====================*/
void dfs(int s)
{
	for(auto idx:v[s])
	{
		dfs(idx);
		sum[s]+=sum[idx];
	}
}
/*====================*/
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		sum[a[i]]++;
	}
	int root=a[n];
	vis[root]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(vis[a[i]])continue;
		v[a[i+1]].push_back(a[i]);
		vis[a[i]]=1;
	}
	dfs(root);
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
//	for(int i=1;i<=m;i++)
//	{
//		cout<<sum[i];
//		if(i!=m)cout<<" ";
//	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
