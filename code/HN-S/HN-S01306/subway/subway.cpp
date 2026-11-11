#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c,d,q,w[505],t[505],ans;
struct node{
	ll x,t;
};
map<pair<ll,ll>,ll> mp; 
vector<ll> jl[505];
vector<node> v[505];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > qu;
void dj(ll x,ll y){
	for(ll i=0;i<jl[x].size();i++){
		qu.push({mp[{x,jl[x][i]}],jl[x][i]});
	}
	while(qu.size()>0){
		node f;
		f.x=qu.top().second;
		f.t=qu.top().first;
		qu.pop();
		if(f.t>t[f.x])continue;
		t[f.x]=f.t;
		for(ll i=0;i<jl[f.x].size();i++){
			if(t[f.x]+mp[{f.x,jl[f.x][i]}]<t[jl[f.x][i]])qu.push({mp[{f.x,jl[f.x][i]}]+t[f.x],jl[f.x][i]});
		}
	}
	ans=t[y];
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=0;j<k;j++){
			ll x,y;
			cin>>x>>y;
			v[i].push_back({x,y});
		}
		for(ll j=0;j<v[i].size();j++){
			for(ll k=j+1;k<v[i].size();k++){
				if(mp[{v[i][k].x,v[i][j].x}]==0)jl[v[i][k].x].push_back(v[i][j].x),jl[v[i][j].x].push_back(v[i][k].x),mp[{v[i][k].x,v[i][j].x}]=v[i][k].t+v[i][j].t,mp[{v[i][j].x,v[i][k].x}]=v[i][k].t+v[i][j].t;
				if(v[i][k].t+v[i][j].t<mp[{v[i][k].x,v[i][j].x}])mp[{v[i][k].x,v[i][j].x}]=v[i][k].t+v[i][j].t,mp[{v[i][j].x,v[i][k].x}]=v[i][k].t+v[i][j].t;
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ans=0;
		ll x,y;
		cin>>x>>y;
		for(ll i=0;i<=25;i++){
			t[i]=999999999999;
		}
		while(qu.size()>0){
			qu.pop();
		}
		t[x]=0;
		dj(x,y);
		cout<<ans+w[y]+w[x]<<"\n";
	}
	return 0;
} 
