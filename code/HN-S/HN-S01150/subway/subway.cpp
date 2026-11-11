#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
	ll x,v;
	bool operator<(const node& a)const{
		return v>a.v;
	}
};
ll kkk,n,m,ddd,q,idx,d[5000001],b[5000001];
map<ll,ll>mp;
vector<node>a[5000001];
void dij(ll x){
	priority_queue<node>q;
	q.push({x,0});
	for(ll i=1;i<=idx;i++){
		d[i]=1e18;
		b[i]=0;
	}
	d[x]=0;
	while(q.size()){
		node x=q.top();
		q.pop();
		if(b[x.x]) continue;
		b[x.x]=1;
		for(ll i=0;i<a[x.x].size();i++){
			ll y=a[x.x][i].x,w=a[x.x][i].v;
			if(d[y]>d[x.x]+w){
				d[y]=d[x.x]+w;
				q.push({y,d[y]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>kkk>>n>>m>>ddd>>q;
	for(ll i=1;i<=m;i++){
		ll x;
		cin>>x;
		if(mp[i]==0) mp[i]=++idx;
		if(mp[i+100000]==0) mp[i+100000]=++idx;
		a[mp[i]].push_back({mp[i+100000],x});
		a[mp[i+100000]].push_back({mp[i],x});
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll prex;
		for(ll j=1;j<=k;j++)
		{
			ll x,t;
			cin>>x>>t;
			if(mp[x+100000+100000*i]==0) mp[x+100000+100000*i]=++idx;
			a[mp[x+100000]].push_back({mp[x+100000+100000*i],t});
			a[mp[x+100000+100000*i]].push_back({mp[x+100000],t});
			if(j==1){
				prex=x;
				continue;
			}
			else{
				a[mp[x+100000+100000*i]].push_back({mp[prex+100000+100000*i],0});
				a[mp[prex+100000+100000*i]].push_back({mp[x+100000+100000*i],0});
				prex=x;
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		dij(mp[x]);
		cout<<d[mp[y]]<<'\n';
	}
	return 0;
}

