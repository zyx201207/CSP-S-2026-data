#include<bits/stdc++.h>
using namespace std;
struct node{
	int y,z;
	node(int a,int b){
		y=a,z=b;
	}
};
long long c,n,m,d,q;
long long mi;
long long w[500010];
vector<node>e[20];
pair<int,int>cc[20];
inline void dfs(int x,int y,int z,long long t){
	if(z>4)
	    return;
	if(x==y){
		mi=min(mi,t);
		return;
	}
	int ll=e[x].size();
	for(int yy=0;yy<ll;yy++)
		dfs(e[x][yy].y,y,z+1,t+e[x][yy].z);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int l=1;l<=n;l++){
    	int k;
    	scanf("%d",&k);
    	for(int j=1;j<=k;j++)
    	    scanf("%d%d",&cc[j].first,&cc[j].second);
    	for(int i=1;i<=k;i++)
    	    for(int j=i+1;j<=k;j++){
    	    	e[cc[i].first].push_back(node(cc[j].first,cc[i].second+cc[j].second));
    	    	e[cc[j].first].push_back(node(cc[i].first,cc[i].second+cc[j].second));
			}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		mi=1e18;
		dfs(u,v,0,0);
		printf("%lld\n",mi+w[u]+w[v]);
	}
	return 0;
}
