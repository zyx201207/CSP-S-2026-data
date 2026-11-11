#include<bits/stdc++.h>
using namespace std;
const int N=5e2+1,M=5e5+1;
int W[M],t[M][N];
int c,n,m,d,q;
long long g[N][N];
vector<int>S[M];
void Floyed(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int tt,ai;
			cin>>ai>>tt;
			t[ai][i]=tt;
			S[ai].push_back(i);
		}
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		for(int j=0;j<S[i].size();j++)
			for(int k=j+1;k<S[i].size();k++){
				int u=S[i][j],v=S[i][k];
				g[u][v]=(long long)(t[i][u]+t[i][v]);
				g[v][u]=g[u][v];
			}
	}
	for(int i=1;i<=n;i++) g[i][i]=0;
	Floyed();
	while(q--){
		int u,v;cin>>u>>v;
		long long ans=1e18;
		if(u==v) cout<<0<<'\n';
		else{
			for(int i=0;i<S[u].size();i++)
				for(int j=0;j<S[v].size();j++)
					ans=min(ans,g[S[u][i]][S[v][j]]+((long long)t[u][S[u][i]])+((long long)t[v][S[v][j]]));
			ans+=(long long)(W[u]+W[v]);
			cout<<ans<<'\n';			
		}
	}
	return 0;
}