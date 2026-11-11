#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
const int N=1e6+5,INF=1e18,M=5e5+1005;
int ans;
int c,n,k,m,d,q1;
int zhi[N],x,y,dis2[505][505];
vector<pi>go[N];
deque<int>q;
bool vis[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)cin>>zhi[i];
	memset(dis2,0x3f,sizeof(dis2));
	for(int i=1;i<=n;i++)dis2[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			for(auto r:go[x])
			{
				dis2[r.first][i]=min(dis2[r.first][i],r.second+y);
				dis2[i][r.first]=dis2[r.first][i];
			}
			go[x].push_back({i,y});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
	for(int i=1;i<=q1;i++)
	{
		cin>>x>>y;
		ans=INF;
		for(auto j:go[x])
			for(auto r:go[y])
				ans=min(ans,dis2[j.first][r.first]+j.second+r.second);
		cout<<ans+zhi[x]+zhi[y]<<'\n';
	}
	return 0;
}