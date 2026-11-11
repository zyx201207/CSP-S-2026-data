#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,inf=LLONG_MAX>>1;
int test,n,m,d,q,ans;
int w[M],a[N][N];
vector<pair<int,int> > edge[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,0x3f,sizeof a);
	cin>>test>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int pos,t;
			cin>>pos>>t;
			for(int j=0,number,times;j<edge[pos].size();++j)
			{
				tie(number,times)=edge[pos][j];
				if(a[number][i]>times+t)
					a[number][i]=a[i][number]=times+t;
			}
			edge[pos].push_back({i,t});
		}
		a[i][i]=0;
	}
	for(int i=1;i<=n;++i)
		for(int k=1;k<=n;++k)
			for(int j=1;j<=n;++j)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	while(q--)
	{
		ans=inf;
		int x,y;
		cin>>x>>y;
		for(int i=0;i<edge[x].size();++i)
			for(int j=0;j<edge[y].size();++j)
				ans=min(ans,a[edge[x][i].first][edge[y][j].first]+edge[x][i].second+edge[y][j].second);
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}