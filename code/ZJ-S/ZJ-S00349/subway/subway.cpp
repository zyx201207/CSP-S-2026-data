#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=5e5+10;
ll c,n,m,d,q;
ll w[M];
ll dis[N][N];
struct node{
	ll v;ll w;
};
vector<node>zt[M];
int main(){
//	cout<<sizeof(w)+sizeof(dis)+sizeof(zt)<<"\n";
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	ll cnt=0;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		dis[i][i]=0;
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			zt[a].push_back(node{i,t});
//			cnt++;
		}
	}
//	cout<<cnt;
//	return 0;
	for(ll i=1;i<=m;i++){
//		cout<<zt[i].size()<<" "<<i<<"\n";
		ll len=zt[i].size();
//		cout<<len<<"\n";
		for(ll j=0;j<len;j++){
			for(ll k=j+1;k<len;k++){
				ll u=zt[i][j].v;
				ll v=zt[i][k].v;
//				cout<<"u:"<<u<<" v:"<<v<<"\n";
				dis[u][v]=min(dis[u][v],(ll)zt[i][j].w+zt[i][k].w);
				dis[v][u]=dis[u][v];
			}
		}
	}
//	return 0;;
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
////		cout<<"\n";
//	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll s,t;
		cin>>s>>t;
		ll ans=LONG_LONG_MAX;
		for(ll i=0;i<zt[s].size();i++){
			ll u=zt[s][i].v;
			for(ll j=0;j<zt[t].size();j++){
				ll v=zt[t][j].v;
				ans=min(ans,dis[u][v]+zt[s][i].w+zt[t][j].w);
			}
		}
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
//green
/*
?
shang wu de dui pai mei xie srand(time(NULL))
jing zhong chang ming
gu ji gua wan le.
:(
S zu neng bu gua fen ma
yu qi 100+100+60+15=283
I love CCF
CCF give me 400pts on J
give me 283 pts on S
pleaseeeeeeeee
//green
*/