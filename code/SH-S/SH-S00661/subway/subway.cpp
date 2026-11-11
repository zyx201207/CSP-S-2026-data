#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
#define INF 1001001001001001001ll
using namespace std;
int n,m,d,q,w[M],dg[M],f[N][N];//dg[x]<=20
vector<int> to[M],ev[M];
void solve(){
	cin>>n>>n>>m>>d>>q;
	for(int x=1;x<=m;x++){
		cin>>w[x];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=0,x,v;j<k;j++){
			cin>>x>>v;
			to[x].push_back(i);
			ev[x].push_back(v);
			++dg[x];
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			f[u][v]=INF;
		}
		f[u][u]=0;
	}
	for(int x=1;x<=m;x++){
		for(int i=0;i<dg[x];i++){
			for(int j=i+1;j<dg[x];j++){
				int u=to[x][i],v=to[x][j];
				f[u][v]=f[v][u]=min(f[u][v],ev[x][i]+ev[x][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
			}
		}
	}
	for(int r=1,x,y;r<=q;r++){
		cin>>x>>y;
		int ans=INF;
		for(int i=0;i<dg[x];i++)
			for(int j=0;j<dg[y];j++){
				ans=min(ans,ev[x][i]+ev[y][j]+f[to[x][i]][to[y][j]]);
			}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
