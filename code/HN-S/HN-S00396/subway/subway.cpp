#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e4+10;
const int N=510;
int w[M]{};
vector <pair<int,int>> e[M+N]{};
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
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back({m+i,y});
			e[m+i].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		priority_queue <pair<int,int>> q;
		q.push({0,x});
		int ans=999999999;
		int z[m+n+10]{};
		memset(z,0x3f,sizeof(z));
		while(!q.empty()){
			int v=q.top().second,u=q.top().first;
			q.pop();
			if(v==y){
				ans=min(ans,u+w[x]+w[y]);
			}
			if(u>z[v]){
				continue;
			}
			z[v]=u;
			for(auto yy:e[v]){
				int ee=yy.first,vv=yy.second;
				if(u+vv>z[ee]){
					continue;
				}
				q.push({u+vv,ee});
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
