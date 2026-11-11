#include <bits/stdc++.h>
using namespace std;
struct Node{
	int d,m;
}g[1000005];
int c,t,n,k,y[1000005],dist[1000005];
vector<int> e[1000005];
bool cmp(const Node &a,const Node &b){
	return a.d>b.d;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(y,0,sizeof y);
		memset(dist,127,sizeof dist);
		vector<int> y(k+1,0);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			g[i].m=i,g[i].d=e[i].size();
		}
		sort(g+1,g+n+1,cmp);
		int tot=0;
		for(int i=1;i<=k;i++){
			y.push_back(g[i].m);
			tot+=g[i].d;
		}
		if((n-1)*2/tot==1){
			printf("%d\n",1);
		}
		else{
			printf("%d\n",(n-1)*2/tot);
		}
	}
	return 0;
}
