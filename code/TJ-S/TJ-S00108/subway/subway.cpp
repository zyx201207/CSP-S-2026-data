#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=5e5+1000;
struct nd{
	int v;
	ll wd;
};
int c,n,m,d,q;
int w[mxn],vis[mxn];
ll dis[mxn];
vector<nd> sz[mxn];
ll f(int x,int y){
	priority_queue< pair<ll,int> > nw;
	nw.push({0,x});
	for(int i=1;i<=m+n;i++) {
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[x]=0;
	while(!nw.empty()){
		int p=nw.top().second;
		nw.pop();
		if (vis[p]) continue;
		vis[p]=1; 
		for(int j=0;j<sz[p].size();j++){
			int v=sz[p][j].v;
			ll wd=sz[p][j].wd;
			//cout<<v<<" ";
			if (dis[v]>dis[p]+wd){
				dis[v]=dis[p]+wd;
				if (!vis[v]) nw.push({-dis[v],v});
			}
		} 
	} 
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}	
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			sz[a].push_back({m+i,t});
			sz[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int st,to;
		scanf("%d%d",&st,&to);
		printf("%lld\n",f(st,to)+1ll*w[st]+1ll*w[to]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
