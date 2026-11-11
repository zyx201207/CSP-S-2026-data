#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=510,M=5e5+10;
int C,n,m,d,q;
int w[M],edges[M][N];
int book[N];
vector<int> chain[M],mem[N];
void solve(int start,int en)
{
	cout<<w[start]+w[en]<<"\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	memset(edges,0x3f,sizeof(edges));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,cost;
			cin>>u>>cost;
			chain[u].push_back(i);
			mem[i].push_back(u);
			edges[u][i]=cost;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}
