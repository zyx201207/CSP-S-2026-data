#include<bits/stdc++.h>
#define ll long long
#define db double
#define endl '\n'
#define Max(a,b,c) max(a,max(b,c))
#define Min(a,b,c) min(a,min(b,c))
using namespace std;
const int N=5e5+7;
const int mod=998244353;
const int INF=1e9+7;
const int M=500;
/*
线段树4倍，数组清空，注意longlong,优先暴力 
while(1) rp++;不犯糖 
*/

struct node{
	int u,v,w;
}dis[N];
int cmp(node a,node b){return a.w<b.w;}
struct nod{
	int v,w;
};
int f[5005][5005];
int w[N],a[M][N],t[M][N];
map<int,int>mp[N];
int tot;
int m;
void solve(){
	int c,n,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		for(int j=2;j<=k;j++){
			int u=a[i][j],v=a[i][j-1],w=t[i][j];
			dis[++tot].u=u;dis[tot].v=v;dis[tot].w=w;
		}
	}
	sort(dis+1,dis+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int u=dis[i].u;
		int v=dis[i].v;
		int w=dis[i].w;
		if(!mp[u][v]&&!mp[v][u]){
			f[u][v]=w;
			f[v][u]=w;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				//cout<<i<<" "<<j<<" "<<k<<" "<<endl;
				f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[y]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	/*
	int T;
	cin>>T;
	while(T--)*/
	    solve();
	return 0;
}//Oct31==Dec25?
