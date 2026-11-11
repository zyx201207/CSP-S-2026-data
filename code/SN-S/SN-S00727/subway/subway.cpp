#include<bits/stdc++.h>
#define N 500005
#define mod 998244353
#define il inline
#define ll long long
#define P array<int,2>
using namespace std;
namespace xzz{
bool beg;
int T=1;
int n,m,d,q,w[N];
vector<int> a[505],b[505];
vector<P> t[N];
ll dis[505][505];
void newmain(){
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	dis[i][j]=0x3f3f3f3f3f3f3f3f;
		dis[i][i]=0;
	}
	for(int i=1,k;i<=n;i++){
		cin>>k,a[i].resize(k),b[i].resize(k);
		for(int j=0;j<k;j++)	cin>>a[i][j]>>b[i][j],t[a[i][j]].push_back({i,j});
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=j+1;k<t[i].size();k++){
				int x=t[i][j][0],y=t[i][k][0];
				dis[x][y]=dis[y][x]=min(dis[x][y],1ll*b[x][t[i][j][1]]+b[y][t[i][k][1]]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&i!=k&&j!=k)	dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto p:t[u]){
			for(auto q:t[v]){
				ans=min(ans,dis[p[0]][q[0]]+w[u]+w[v]+b[p[0]][p[1]]+b[q[0]][q[1]]);
			}
		}
		cout<<ans<<'\n';
	}
}
bool ed;
void main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(T--)	newmain();
	return;
}
}
signed main(){xzz::main();return 0;}

