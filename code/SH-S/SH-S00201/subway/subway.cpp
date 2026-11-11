#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,q,w[N],a[N][22],t[N][22],g[507][507];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;++i) g[i][i]=0;
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			for(int j=1;j<=a[x][0];++j)
				g[a[x][j]][i]=g[i][a[x][j]]=min(g[i][a[x][j]],y+t[x][j]);
			++a[x][0];
			a[x][a[x][0]]=i,t[x][a[x][0]]=y;
		}
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=4e18+7;
		for(int i=1;i<=a[x][0];++i)
			for(int j=1;j<=a[y][0];++j)
				ans=min(ans,t[x][i]+t[y][j]+g[a[x][i]][a[y][j]]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
