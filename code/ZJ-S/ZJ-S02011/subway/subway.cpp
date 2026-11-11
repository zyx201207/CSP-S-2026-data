#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[500005],sw[505][505];
struct node{
	ll t,w;
};
vector<node> v[500005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			sw[i][j]=1e18;
		}
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<v[i].size();j++){
			for(ll ij=j+1;ij<v[i].size();ij++){
				ll t1=v[i][j].t,t2=v[i][ij].t,wt=v[i][j].w+v[i][ij].w;
				sw[t1][t2]=min(sw[t1][t2],wt);
				sw[t2][t1]=min(sw[t2][t1],wt);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll k=1;k<=n;k++){
			for(ll j=1;j<=n;j++){
				sw[i][j]=min(sw[i][j],sw[i][k]+sw[j][k]);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<sw[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(ll i=1;i<=q;i++){
		ll x,y,ans=1e18;
		cin>>x>>y;
		for(ll ii=0;ii<v[x].size();ii++){
			for(ll j=0;j<v[y].size();j++){
				if(v[x][ii].t==v[y][j].t){
					ans=min(ans,v[x][ii].w+v[y][j].w);
					continue;
				}
				ans=min(ans,v[x][ii].w+v[y][j].w+sw[v[x][ii].t][v[y][j].t]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}