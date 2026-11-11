#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],dis[1001][1001],vis[1001],vs[600001],ds[600001];
struct node{
	long long pos,step;
	bool operator<(const node x)const{
		return x.step<step;
	}
};
vector<node> v[600001];
int dij(int st,int ed){
	if(m<=1000){
		vis[st]=1;
		for(int i=1;i<=m+n;i++){
			dis[st][i]=1e15;
		}
	}
	for(int i=1;i<=m+n;i++){
		vs[i]=0;
		ds[i]=1e15;
	}
	priority_queue<node> pq;
	pq.push({st,0});
	while(!pq.empty()){
		node now=pq.top();
		pq.pop();
		if(now.pos==ed&&m>1000)return ds[ed]+w[st]+w[ed];
		if(vs[now.pos])continue;
		vs[now.pos]=1;
		for(int i=0;i<v[now.pos].size();i++){
			long long nxt=v[now.pos][i].pos,nst=v[now.pos][i].step+now.step;
			if(nst<ds[nxt]){
				ds[nxt]=nst;
				if(m<=1000){
					dis[st][nxt]=w[st]+w[nxt]+nst;
				}
				pq.push({nxt,nst}); 
			}
		}
	}
	return dis[st][ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			v[m+i].push_back({x,y});
			v[x].push_back({m+i,y});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(m<=1000&&vis[x]==1){
			cout<<dis[x][y]<<endl;
			continue;
		}
		cout<<dij(x,y)<<endl;
	}
}






