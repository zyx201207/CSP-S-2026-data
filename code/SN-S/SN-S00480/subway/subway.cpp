//SN-S00480 西安铁一中滨河高级中学 李明轩  
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

// n线路数   m站数   d每个地铁站最多被几条线路经过   r出行计划数

struct edge{
	ll to,cost;
};
vector<edge> g[500005];
priority_queue< pii,vector<pii>,greater<pii> > q;
ll ccc,n,m,d,r;
ll dis[500005];
ll timem[500005];//进出站时间 
ll k[505];//线路经过站数 
ll sum[500005];

/*int find(ll a){
	if(f[a]==a) return ;
	else return f[a]=find(a);
}

int join(ll a,ll b){
	ll x=find(a),y=find(b);
	return f[a]=y;
}*/

void init(){
	for(ll i=1;i<=500005;i++){
		dis[i]=INT_MAX;
	}
	while(!q.empty()){
		q.pop();
	}
	return;
}

void dij(ll s){
	init();
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pii ntop=q.top();
		q.pop();
		ll np=ntop.second,d=ntop.first;
		if(dis[np]<=d) continue;
		for(ll i=0;i<g[np].size();i++){
			ll nt=g[np][i].to,nc=g[np][i].cost;
			if(dis[nt]>nc+dis[i]){
				dis[nt]=nc+dis[i];
				q.push({dis[nt],nt});
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>r;
	for(ll i=1;i<=m;i++){
		cin>>timem[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		ll aaa[500005];
		for(ll j=1;j<=k[i];j++){
			ll xx;
			cin>>xx>>aaa[xx];
		}
		for(ll j=1;j<=m;j++){
			if(aaa[j]==0) continue;
			else{
				for(ll jj=j+1;jj<=m;jj++){
					if(aaa[jj]!=0){
						g[j].push_back({jj,aaa[j]+aaa[jj]});
						g[jj].push_back({j,aaa[j]+aaa[jj]});
					}
				}
			}
		}
	}
	for(ll i=1;i<=r;i++){
		ll a1=-1,a,b;
		cin>>a>>b;
		if(a==a1) cout<<dis[b]+timem[a]+timem[b]<<'/n';
		else{
			dij(a);
			cout<<dis[b]+timem[a]+timem[b]<<'/n';
		}
		a1=a;
	}
	return 0;
}
