#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int,ll>
const int N=5e2+25,M=5e5+25;

int C,n,m,D,q;
ll sta[M];

vector<pil> pre[M];

ll dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>C>>n>>m>>D>>q;
	for (int i=1;i<=m;++i) cin>>sta[i];
	for (int i=1;i<=n;++i){
		dis[i][i]=0;
		int len;
		cin>>len;
		for (int k=1;k<=len;++k){
			int x;
			ll w;
			cin>>x>>w;
			for (pil j:pre[x]){
				int v=j.first;
				ll vt=j.second;
				dis[i][v]=dis[v][i]=min(dis[i][v],w+vt);
			}
			pre[x].push_back({i,w});
		}
	}
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i=1;i<=q;++i){
		int s,t;
		cin>>s>>t;
		ll nans=0x3f3f3f3f3f3f3f3f;
		for (pil j:pre[s]){
			int u=j.first;
			ll ndu=j.second;
			for (pil k:pre[t]){
				int v=k.first;
				ll ndv=k.second;
				nans=min(nans,ndu+dis[u][v]+ndv);
			}
		}
		cout<<nans+sta[s]+sta[t]<<'\n';
	}
	return 0;
}//subway
