#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Ztxl{
public:
	int xln;
	ll t;
};
class Node{
public:
	int n;
	ll step;
	bool operator<(const Node& other) const{
		return step>other.step;
	}
};
int c=0,n=0,m=0,d=0,q=0;
ll w[500005]={};
vector<Ztxl> zts[500005];
vector<pair<int,ll>> a[505];
ll stepa[505]={};
ll all_stepa[505][505]={};
priority_queue<Node> pq;
void djstl(int st){
	while(!pq.empty()){
		pq.pop();
	}
	for(int i=1;i<=n;i++){
		stepa[i]=1e18;
	}
	stepa[st]=0;
	pq.push({st,0});
	while(!pq.empty()){
		Node now=pq.top();
		pq.pop();
		if(now.step!=stepa[now.n]) continue;
		for(int i=0;i<a[now.n].size();i++){
			int to=a[now.n][i].first;
			ll val=a[now.n][i].second;
			if(stepa[now.n]+val<stepa[to]){
				stepa[to]=stepa[now.n]+val;
				pq.push({to,stepa[to]});
			}
		}
	}
	for(int j=1;j<=n;j++){
		all_stepa[st][j]=stepa[j];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=0;j<k;j++){
			int ztnj=0;
			ll tj=0;
			cin>>ztnj>>tj;
			zts[ztnj].push_back({i,tj});
		}
	}
	for(int k=1;k<=m;k++){
		int lz=zts[k].size();
		for(int i=0;i<lz;i++){
			for(int j=i+1;j<lz;j++){
				int x=zts[k][i].xln;
				int y=zts[k][j].xln;
				ll z=zts[k][i].t+zts[k][j].t;
				a[x].push_back({y,z});
				a[y].push_back({x,z});
			}
		}
	}
	for(int i=1;i<=n;i++){
		djstl(i);
	}
	for(int qi=0;qi<q;qi++){
		int st=0,ed=0;
		cin>>st>>ed;
		ll ans=1e18;
		for(int i=0;i<zts[st].size();i++){
			for(int j=0;j<zts[ed].size();j++){
				ll stw=w[st]+zts[st][i].t;
				ll edw=w[ed]+zts[ed][j].t;
				ans=min(ans,stw+all_stepa[zts[st][i].xln][zts[ed][j].xln]+edw);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}