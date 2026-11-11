#include <iostream>
#include <cstring>
#include <vector>
#define N 505
#define M 500005
#define fi first
#define se second
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int cst[M],dis[N][N];
vector<pair<int,int> > sta[M];
signed main()
{
	cin.tie(0);ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,k,n,m,d,t,q,w,e;
	cin>>i>>n>>m>>d>>t;
	for (i=1;i<=m;i++)  cin>>cst[i];
	for (i=1;i<=n;i++){
		cin>>q;
		for (j=1;j<=q;j++){
			cin>>w>>e;
			sta[w].push_back({i,e});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (i=1;i<=n;i++)  dis[i][i]=0;
	for (i=1;i<=m;i++){
		for (j=0;j<sta[i].size();j++){
			for (k=j+1;k<sta[i].size();k++){
				int u=sta[i][j].fi,v=sta[i][k].fi,val=sta[i][j].se+sta[i][k].se;
				dis[u][v]=dis[v][u]=min(dis[u][v],val);
			}
		}
	}
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++){
			for (k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for (i=1;i<=t;i++){
		cin>>q>>w;int ans=inf;
		for (j=0;j<sta[q].size();j++){
			for (k=0;k<sta[w].size();k++){
				int u=sta[q][j].fi,v=sta[w][k].fi,val=sta[q][j].se+sta[w][k].se;
				ans=min(ans,dis[u][v]+val);
			}
		}
		ans+=cst[q]+cst[w];cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
