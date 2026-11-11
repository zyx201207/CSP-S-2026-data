#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dis[507][507],c,n,m,d,q,jin[500007];
struct Q{
	ll l,r;
}que[100007];
vector<pair<ll,ll> >jg[500007];
void main1(){
	memset(dis,63,sizeof(dis));
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<jg[i].size();j++){
			for(ll k=j+1;k<jg[i].size();k++){
				ll z1=jg[i][j].first,z2=jg[i][k].first,t1=jg[i][j].second,t2=jg[i][k].second;
				dis[z1][z2]=min(dis[z1][z2],t1+t2);
				dis[z2][z1]=min(dis[z2][z1],t1+t2);
			}
		}
	}
	for(ll i=1;i<=n;i++)dis[i][i]=0;
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==k||i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(ll i=1;i<=q;i++){
		ll ans=LLONG_MAX;
		for(ll j=0;j<jg[que[i].l].size();j++){
			for(ll k=0;k<jg[que[i].r].size();k++){
				ll z1=jg[que[i].l][j].first,z2=jg[que[i].r][k].first;
				ans=min(ans,dis[z1][z2]+jg[que[i].l][j].second+jg[que[i].r][k].second);
			}
		}
		cout<<ans+jin[que[i].l]+jin[que[i].r]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>jin[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			jg[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=q;i++)cin>>que[i].l>>que[i].r;
	main1();
//	if(c<=23){
//		main5();return 0;
//	}
	return 0;
}
/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2

*/
