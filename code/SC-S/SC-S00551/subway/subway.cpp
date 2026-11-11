#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const ll N=510,M=5e5+10;
struct Node{
	ll xl,tm;
};
ll c,n,m,d,q;
ll w[M];
Node t[M][30];
ll ind[M];
ll G[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k; cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,val; cin>>x>>val;
			t[x][++ind[x]]={i,val};
		}
	}
	memset(G,0x3f,sizeof(G));
	for(ll i=1;i<=n;i++) G[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=ind[i];j++){
			for(ll k=j+1;k<=ind[i];k++){
				G[t[i][j].xl][t[i][k].xl]=G[t[i][k].xl][t[i][j].xl]=min(G[t[i][k].xl][t[i][j].xl],t[i][j].tm+t[i][k].tm);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	while(q--){
		ll x,y; cin>>x>>y;
		ll ans=1e18;
		for(ll i=1;i<=ind[x];i++){
//			cout<<"hi "<<i<<"\n";
			for(ll j=1;j<=ind[y];j++){
//				cout<<"hello "<<i<<","<<j<<"\n";
				ans=min(ans,w[x]+w[y]+t[x][i].tm+t[y][j].tm+G[t[x][i].xl][t[y][j].xl]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
把线路看成节点
相邻两个点就是这两条线路有公共站，边权为直接相加取 min
然后跑 Floyd
对于询问，遍历以何线为始何线为终 
 
*/