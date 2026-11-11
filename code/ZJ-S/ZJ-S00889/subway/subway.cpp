#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=500+10;
const int mod=1e9+7;
const int inf=1e17;
inline int mm(int X,int MOD=mod){
	return (X%MOD+MOD)%MOD;
}
int n,m,k;
int a[N];
int dis[M][M];
vector<pii> e[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int Case;
	cin>>Case;
	cin>>n>>m>>k;
	int Q;
	cin>>Q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int v=i,u,w;
			cin>>u>>w;
			e[u].push_back({v,w});
		}
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
			if(i==j){
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(pii p1:e[i]){
			int u=p1.first;
			int w1=p1.second;
			for(pii p2:e[i]){
				int v=p2.first;
				int w2=p2.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(Q--){
		int s,t;
		cin>>s>>t;
		int ans=inf;
		for(pii p1:e[s]){
			int u=p1.first;
			int w1=p1.second;
			for(pii p2:e[t]){
				int v=p2.first;
				int w2=p2.second;
				ans=min(ans,dis[u][v]+w1+w2);
			}
		}
		cout<<ans+a[s]+a[t]<<endl;
	}
	return 0;
}
