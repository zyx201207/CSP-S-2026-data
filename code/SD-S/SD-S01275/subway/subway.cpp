#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid (((ll)l+r)>>1)
#define _line asdf
ll c,n,m,d,q,dis[505][505],w[500005];
vector<pair<ll,ll> >_line[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll kk;
		cin>>kk;
		while(kk--){
			ll x,y;
			cin>>x>>y;
			_line[x].push_back({i,y});
		}
	}
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)if(i!=j)dis[i][j]=1e18;
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<_line[i].size();j++){
			for(ll k=0;k<_line[i].size();k++){
				if(j==k)continue;
				dis[_line[i][j].first][_line[i][k].first]=dis[_line[i][k].first][_line[i][j].first]=
				min(dis[_line[i][j].first][_line[i][k].first],_line[i][j].second+_line[i][k].second);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
/*	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<'\n';
	}
*/	while(q--){
		ll x,y,res=1e18;
		cin>>x>>y;
		for(ll i=0;i<_line[x].size();i++){
			for(ll j=0;j<_line[y].size();j++){
				res=min(res,_line[x][i].second+_line[y][j].second+dis[_line[x][i].first][_line[y][j].first]);
			}
		}
		cout<<res+w[x]+w[y]<<'\n';
	}
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
