#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+10;
int c,n,m,d,ques,init[M],ww[N][N];
struct edge{
	int to,w;
};
vector<edge> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>ques;
	for(int i=1;i<=m;i++) cin>>init[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			g[a].emplace_back((edge){i,t});
		}
	}
	memset(ww,0x3f,sizeof ww);
	for(int i=1;i<=m;i++){
		int sz=g[i].size();
		for(int p=0;p<sz;p++){
			for(int q=p+1;q<sz;q++){
				int u=g[i][p].to,v=g[i][q].to,W=g[i][p].w+g[i][q].w;
				ww[u][v]=min(ww[u][v],W);
				ww[v][u]=min(ww[v][u],W);
			}
		}
	}
	for(int i=1;i<=n;i++) ww[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++) ww[u][v]=min(ww[u][v],ww[u][k]+ww[k][v]);
		}
	}
	while(ques--){
		int x,y;cin>>x>>y;
		int res=1e18;
		for(edge a : g[x]){
			for(edge b : g[y]){
				res=min(res,init[x]+a.w+b.w+ww[a.to][b.to]+init[y]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}