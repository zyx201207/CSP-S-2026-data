#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PID "subway"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
const ll V=5e5+5,B=505;
int a[50005][505];
ll c,n,m,D,q,w[V];
struct node{
	ll id,line;
};
vector<node> g[V];

ll dijk(ll& st,ll& ed){
	ll dist[m][n],vis[m],flag=1;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	pq.push({0,{st,0}});
	dist[st][0]=0;
	vis[st]=1;
	while(!pq.empty()){
		pair<ll,pair<ll,ll>> tmp=pq.top();pq.pop();
		ll d=tmp.first,u=tmp.second.first,ul=tmp.second.second;
		if(d>dist[u][ul]) continue;
		if(u==ed) return d+w[st]+w[ed]+a[ed][ul]+a[st][flag];
		for(node& son:g[u]){
			int v=son.id,vl=son.line;
			if(vis[v]==1) continue;
			vis[v]=1;
			if(ul==0 || vl==ul){
				if(dist[v][vl]>dist[u][ul]){
					if(ul==0) flag=vl;
					dist[v][vl]=dist[u][ul];
				}
			}else{
				if(dist[v][vl]>dist[u][ul]+a[u][ul]+a[u][vl]) 
					dist[v][vl]=dist[u][ul]+a[u][ul]+a[u][vl];
			}
			pq.push({dist[v][vl],{v,vl}});
		}
	}
	return -1;
}

signed main(){
	FIN;
	FOU;
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		int la=-1;
		for(int j=1,z,t;j<=k;j++){
			cin>>z>>t;
			a[z][i]=t;
			if(la!=-1){
				g[la].push_back({z,i});
				g[z].push_back({la,i});
			} 
			la=z;
		}
	}
	ll st,ed;
	while(q--){
		cin>>st>>ed;
		cout<<dijk(st,ed)<<endl;
	}
	return 0;
}

