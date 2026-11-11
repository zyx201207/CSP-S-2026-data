#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct Node{
	ll end,c,ind;
	bool operator<(const Node a)const{
		return a.c<c;
	}
}u,v;
//ppppppppppppp
int c,n,m,d,q;
ll w[500005],x[500][50005],y[500][50005];
vector<Node> mp[500005];
bool lvis[500005];
ll dij(int s,int r,int e){
	priority_queue<Node> pq;
	int dis[500005];
	memset(dis,0x7f7f7f7f,sizeof(dis));
	dis[s]=w[s];
	pq.push({s,0,r});
	while(!pq.empty()){
		u=pq.top();
		pq.pop();
		if(u.c>dis[u.end])continue;
		for(int i=0;i<mp[u.end].size();i++){
			v=mp[u.end][i];
			if(dis[u.end]+v.c<dis[v.end]){
				dis[v.end]=dis[u.end]+v.c;
				pq.push({v.end,dis[v.end],v.ind});
			}
			
		}
	}
	return dis[e]+w[e];
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[i][j]>>y[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int l=2;l<=k;l++){
				mp[x[i][j]].push_back({x[i][l],y[i][j]+y[i][l],i});
				mp[x[i][l]].push_back({x[i][j],y[i][j]+y[i][l],i});
			}
		}
	}
	while(q--){
		memset(lvis,0,sizeof(lvis));
		ll s,e;
		cin>>s>>e;
		ll minx=0x3f3f3f3f;
		for(int i=0;i<mp[s].size();i++){
			if(!lvis[mp[s][i].ind]){
				minx=min(dij(s,mp[s][i].ind,e),minx);
			}
		}
		cout<<minx<<"\n";
	}
	return 0; 
}

