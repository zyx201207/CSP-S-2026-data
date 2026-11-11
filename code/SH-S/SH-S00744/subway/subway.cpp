#include<bits/stdc++.h>
using namespace std;
#define N 500009
#define int long long
int c,n,m,d,q,tot,f[555][555],w[N],hd[N];
struct edge{ int to,w,nxt; } e[N << 1];
void add(int u,int v,int w){
	e[++tot] = (edge){v,w,hd[u]};
	hd[u] = tot;
}
signed main(){
	// system("fc subway.out subway6.ans"); return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		while(k--){
			int u,t;
			cin>>u>>t;
			add(u,i,t);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int i = 1;i <= m;i++){
		for(int j = hd[i];j;j = e[j].nxt){
			for(int k = e[j].nxt;k;k = e[k].nxt){
				int u = e[j].to,v = e[k].to;
				f[u][v] = min(f[u][v],e[j].w + e[k].w);
				f[v][u] = min(f[v][u],e[j].w + e[k].w);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while(q--){
		int u,v,ans = 1e18;
		cin>>u>>v;
		for(int i = hd[u];i;i = e[i].nxt){
			for(int j = hd[v];j;j = e[j].nxt){
				int x = e[i].to,y = e[j].to;
				ans = min(ans,w[u] + e[i].w + f[x][y] + e[j].w + w[v]);
			}
		}
		cout<<ans<<endl;
	}
}
