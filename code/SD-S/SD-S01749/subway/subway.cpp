#include<bits/stdc++.h>  //rp++
#define int long long
using namespace std;
int c,n,m,d,q,sum,maxx;
int w[5000005],k[5000005],minn[5000005];
int contected[500005][25],val[500005][25];
int a[505][5005],t[505][5005],tot[5000005];
int mp[505][505];
int ans[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j <= n;j++) ans[i][j] = mp[i][j] = 100000000000000;
		for(int j = 1;j <= k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			contected[a[i][j]][++tot[a[i][j]]] = i;
			val[a[i][j]][tot[a[i][j]]] = t[i][j];
		}
	}
	int v;
	for(int u = 1;u <= n;u++){
		for(int i = 1;i <= k[u];i++){
			for(int j = 1;j <= tot[a[u][i]];j++){
				v = contected[a[u][i]][j];
				if(u == v) continue;
				mp[u][v] = min(mp[u][v],t[u][i] + val[a[u][i]][j]);
				ans[v][u] = ans[u][v] = mp[v][u] = mp[u][v];
			}
		} 
	}
	for(int osu = 1;osu <= n;osu++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				ans[i][j] = min(ans[i][j],ans[i][osu] + ans[osu][j]);
			}
		}
	}
	int u;
	while(q--){
		scanf("%lld%lld",&u,&v);
		sum = 9000000000000000;
		for(int i = 1;i <= tot[u];i++){
			for(int j = 1;j <= tot[v];j++){
				if(contected[u][i] == contected[v][j]) sum = min(sum,w[u] + w[v] + val[u][i] + val[v][j]);
				else sum = min(sum,w[u] + w[v] + val[u][i] + val[v][j] + ans[contected[u][i]][contected[v][j]]);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
