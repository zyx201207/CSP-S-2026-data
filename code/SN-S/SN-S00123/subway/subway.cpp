#include<bits/stdc++.h>
#define ll long long
#define N 505
#define M 500005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

namespace WDY_Hodur{

ll c;
ll n,m,d,q;
vector<ll>v[M];
unordered_map<ll,ll>mp[N];

ll k[N];
ll w[M];
ll dis[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll x,y;
			cin>>x>>y;
			v[x].push_back(i);
			mp[i][x]=y;
		}
	}
	for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)dis[i][j]=dis[j][i]=inf;
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<(ll)v[i].size();j++){
			for(ll k=j+1;k<(ll)v[i].size();k++){
				ll x=v[i][j],y=v[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],mp[x][i]+mp[y][i]);
			}
		}
	}
	
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			if(i==k)continue;
			for(ll j=i+1;j<=n;j++){
				if(j==k||i==j)continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--){
		ll x,y;
		ll ans=inf;
		cin>>x>>y;
		for(ll i:v[x]){
			for(ll j:v[y]){
				ans=min(ans,dis[i][j]+mp[i][x]+mp[j][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	
	return 0;
}

}

int main(){
	WDY_Hodur::main();
	return 0;
}
