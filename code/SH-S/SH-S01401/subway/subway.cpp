#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500001],tft[501][501],tnt[501][501];
struct Node{
	int d,u;
	bool operator<(const Node &a)const{return d>a.d;}
};
vector<Node> at[501];
vector<Node> dtz[500001];
priority_queue<Node> pq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int aa,tt;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&aa,&tt);
			at[i].push_back((Node){tt,aa});
			dtz[aa].push_back((Node){tt,i});
		}
		for(int j=1;j<=n;j++) tft[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<dtz[i].size();j++){
			for(int k=0;k<dtz[i].size();k++){
				tft[dtz[i][j].u][dtz[i][k].u]=min(tft[dtz[i][j].u][dtz[i][k].u],dtz[i][j].d+dtz[i][k].d);
			}
		}
	}
	for(int i=1;i<=n;i++){
		pq.push((Node){0,i});
		while(!pq.empty()){
			Node nw=pq.top();
			pq.pop();
			if(tnt[i][nw.u]) continue;
			tnt[i][nw.u]=nw.d;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(tft[nw.u][j]!=1e18) pq.push((Node){nw.d+tft[nw.u][j],j});
			}
		}
		tnt[i][i]=0;
	}
	while(q--){
		int x,y,ans=1e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<dtz[x].size();i++){
			for(int j=0;j<dtz[y].size();j++){
				ans=min(ans,tnt[dtz[x][i].u][dtz[y][j].u]+dtz[x][i].d+dtz[y][j].d);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
