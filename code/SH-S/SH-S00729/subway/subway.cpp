#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fir first
#define sec second

using namespace std;

const int N=5e5+10;
const int INF=1e16;

int G[1005][1005], c, n, m, d, q, w[N], a[N], t[N];
vector<pii>st[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				G[i][j]=INF;
			}
			G[i][i]=0;
		}
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			int k=0;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[j]>>t[j];
			}
			for(int u=1;u<=k;u++){
				for(int v=1;v<=k;v++){
					G[a[u]][a[v]]=min(G[a[u]][a[v]], t[u]+t[v]);
					G[a[v]][a[u]]=min(G[a[v]][a[u]], t[u]+t[v]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
				}
			}
		}
		while(q--){
			int u, v;
			cin>>u>>v;
			cout<<w[u]+w[v]+G[u][v]<<"\n";
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=INF;
			}
			G[i][i]=0;
		}
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			int k=0;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[j]>>t[j];
				st[a[j]].push_back({i, t[j]});
			}
		}
		for(int i=1;i<=m;i++){
			for(auto U:st[i]){
				for(auto V:st[i]){
					int u=U.fir, v=V.fir, cu=U.sec, cv=V.sec;
					if(u==v)continue;
					G[u][v]=min(G[u][v], cu+cv);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
				}
			}
		}
		while(q--){
			int u, v;
			cin>>u>>v;
			if(u==v){
				cout<<w[u]+w[v]<<'\n';
				continue;
			}
			int ans=INF;
			for(auto U:st[u]){
				for(auto V:st[v]){
					ans=min(ans, G[U.fir][V.fir]+U.sec+V.sec);
				}
			}
			cout<<ans+w[u]+w[v]<<'\n';
		}
		return 0;
	}
	return 0;
}
/*
打表过样例
骗分拿省一
NOIP 2026 RP++！

NOIP打完就AFO了qwq 

中国人能飞？
中国人能飞！ 
*/
