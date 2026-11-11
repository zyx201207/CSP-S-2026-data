#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)
#define Tnow double(clock())/CLOCKS_PER_SEC
double TT=double(clock())/CLOCKS_PER_SEC;

const int N=505,M=5e5+5;
const ll inf=1e18;

bool ST;

int id,cnt[M],idx[M][25],n,m,d,q;
ll w[M],dis[N][N],t1[M][25];

bool ED;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>id>>m>>n>>d>>q;
	for(int i=0;i<=m+1;i++) for(int j=0;j<=m+1;j++) dis[i][j]=dis[j][i]=inf;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		int c; cin>>c;
		for(int j=1;j<=c;j++){
			int u;
			ll t;
			cin>>u>>t;
			cnt[u]++;
			t1[u][cnt[u]]=t;
			idx[u][cnt[u]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				int u=idx[i][j],v=idx[i][k];
				dis[u][v]=dis[v][u]=min(dis[u][v],t1[i][j]+t1[i][k]);
			}
		}
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=inf;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				ans=min(ans,dis[idx[u][i]][idx[v][j]]+t1[u][i]+t1[v][j]);
			}
		}cout<<ans+w[u]+w[v]<<endl;
	}
//	cout<<(&ST-&ED)/1024.0/1024.0;
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
