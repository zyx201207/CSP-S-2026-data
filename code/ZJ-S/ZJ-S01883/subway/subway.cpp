#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int MAXN=510,MAXM=2010;
const int INF=0x3f3f3f3f3f3f3f3f;

int w[MAXM];
int c,n,m,d,q,xr,yr;
int tu[MAXM][MAXM],dis[MAXM][MAXM];
int a[MAXN][MAXM],t[MAXN][MAXM],k[MAXN];
int solve(int x,int y){
	return w[x]+dis[x][y]+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if (m>1000) return 0;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	memset(tu,0x3f,sizeof(tu));
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k[i];j++){
			int w=t[i][j],u=a[i][j],v=i+m;
			tu[u][v] = min(tu[u][v],w);
			tu[v][u] = dis[u][v] = dis[v][u] = tu[u][v];
		} 
	}
	for (int i=1;i<=m;i++){
		dis[i][i] = tu[i][i] = 0;
	}
	for (int k=1;k<=n+m;k++){
		for (int i=1;i<=n+m;i++){
			if (dis[k][i]>=INF||dis[i][k]>=INF) continue;
			for (int j=1;j<=n+m;j++){
				if (dis[i][k]<INF&&dis[k][j]<INF&&dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k]+dis[k][j];
					dis[j][i] = dis[i][j];
				}
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		cout<<solve(xr,yr)<<endl;
	}
	return 0;
}
