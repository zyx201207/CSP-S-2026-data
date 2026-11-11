#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=410,N=210;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],ans,dis[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k[i];j++)
			for(int l=1;l<=k[i];l++){
				if(j==l) continue;
				int x=a[i][j],y=a[i][l];
				dis[x][y]=dis[y][x]=min(dis[x][y],t[i][j]+t[i][l]);
			}
	}
	for(int K=1;K<=m;K++)
		for(int i=1;i<=m;i++){
			if(K==i) continue;
			for(int j=1;j<=m;j++){
				if(K==j||i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][K]+dis[K][j]);
			}
		}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<endl;
	}
	return 0;
}
