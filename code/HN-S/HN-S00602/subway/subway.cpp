#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
ll cid,n,m,d,q,w[M],dis[N][N],k,x,y;
struct P{
	ll x,w;
};
vector<P>g[M];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			g[i].push_back({x+n,y});
			g[x+n].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:g[i]){
			for(auto k:g[j.x]){
				if(i==k.x) continue;
				dis[i][k.x]=dis[k.x][i]=min(dis[i][k.x],j.w+k.w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ll ans=1e18;
		for(auto i:g[x+n]){
			for(auto j:g[y+n]){
				ans=min(ans,i.w+dis[i.x][j.x]+j.w);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//30+5min
