#include <bits/stdc++.h>
using namespace std;
int 
void dfs(int x,int time)
{
	nx=
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[500005],k[500005],a[500][50005],u[500],v[500],gong[5005];
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	while(q--)
	{
		cin>>u[q];
		cin>>v[q];//可以用bfs但我不会 
		cout<<v[q];
	}
	return 0;
}
