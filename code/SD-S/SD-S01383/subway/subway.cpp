#include<bits/stdc++.h>
#define ll long long
const int N=505,M=5e5+5;
using namespace std;

int c,n,m,d,q;
int w[M],k[N];
vector<int> a[N],t[N];

namespace Sub1{ //32 pts
	const int N=605;
	int g[N][N];
	inline void solve(){
		memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++){
			for(int j=0;j<k[i];j++){
				a[i][j]+=n;
				g[i][a[i][j]]=g[a[i][j]][i]=t[i][j];
			}
		}
		for(int k=1;k<=n+m;k++){
			for(int i=1;i<=n+m;i++){
				for(int j=1;j<=n+m;j++){
					g[j][i]=g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+g[n+u][n+v]<<'\n';
		}
	}
}


signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	Sub1::solve();
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
