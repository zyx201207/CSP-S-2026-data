#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<pair<int,long long>> a[N];
long long w[N];
long long num;
void dfs(int fu,int u,int zhong,long long lu)
{
	if(u==zhong)
	{
		num=min(num,lu);
		return;
	}
	for(auto &xia:a[u])
	{
		int v=xia.first;
		long long fei=xia.second;
		if(v==fu) continue;
		dfs(u,v,zhong,lu+fei);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int hao,n,m,d,q;
	cin>>hao>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k<=1) continue;
		else
		{
			int x1,x2;
			long long t1,t2;
			cin>>x1>>t1>>x2>>t2;
			a[x1].push_back({x2,t1+t2});
			a[x2].push_back({x1,t1+t2});
		}
	}
	while(q--)
	{
		int x1,x2;
		cin>>x1>>x2;
		num=1e11+10;
		dfs(x1,x1,x2,0);
		cout<<num+w[x1]+w[x2]<<'\n';
	}
	return 0;
}
