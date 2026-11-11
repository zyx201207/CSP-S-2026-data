#include <bits/stdc++.h>
using namespace std;
int n,m,sum[300005],a[500005],b[300005];
vector<int> e[300005];
void dfs(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		dfs(e[u][i]);
		sum[u]+=sum[e[u][i]];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i,sum[a[i]]++;
	for(int i=1;i<=m;i++)e[a[b[i]+1]].push_back(i);
	dfs(0);
	for(int i=1;i<=m;i++)printf("%d ",sum[i]);
	return 0;
}