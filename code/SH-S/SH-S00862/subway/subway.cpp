#include<bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int maxn=500000;
int c,n,m,d,q,a[maxn+10],ans;
vector<pair<int,int> > G[maxn+1000];
int dis[550][550];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<550;i++){
		for(int j=0;j<550;j++){
			dis[i][j]=1e16;
		}
	}
	for(int i=0;i<550;i++){
		dis[i][i]=0;
	}
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int len;
		scanf("%lld",&len);
		for(int j=1;j<=len;j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			G[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=0;k<G[i].size();k++){
				auto pre=G[i][j],las=G[i][k];
				dis[las.f][pre.f]=dis[pre.f][las.f]=min(dis[pre.f][las.f],pre.s+las.s);
			}
		}
	}
//	cout<<dis[1][2];
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=9e18;
		int u,v;
		scanf("%lld%lld",&u,&v);
		for(int i=0;i<G[u].size();i++){
			for(int j=0;j<G[v].size();j++){
				auto pre=G[u][i],las=G[v][j];
				ans=min(ans,dis[pre.f][las.f]+pre.s+las.s);
			}
		}
		printf("%lld\n",ans+a[u]+a[v]);
	}
	return 0;
}
