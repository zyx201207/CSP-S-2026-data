#include<bits/stdc++.h>
using namespace std;
int const N=1e6+6;
vector<int> g[N];
int n,k,w,l1,l2;
int dis[N],maxdis=0;
void dfs1(int x,int fa,int di){
	dis[x]=di;
	if(di>maxdis){
		maxdis=di;
		w=x;
	}
	for(int i=0;i<g[x].size();i++){
		if(i==fa)continue;
		dfs1(i,x,di+1);
	}
}
void solve(){
	dfs1(1,-1,0);
	l1=w;
	maxdis=0;
	dfs1(w,-1,0);
	l2=w;
}
int main(){
    reopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		solve();
	}	
	return 0;
}
