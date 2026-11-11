#include<bits/stdc++.h>
#define int long long
#define maxm 523456
#define maxn 1234
using namespace std;
int c,n,m,d,q,w[maxm],k,a[maxm],t[maxm],x,y,dis[maxn][maxn];
struct node{
	int u,w;
};
vector<node>G[maxn];
queue<node>pq;
void bfs(int s){
	pq.push({s,0});
	dis[s][s]=0;
	while(!pq.empty()){
		node X=pq.front();
		pq.pop();
		int _u=X.u,_w=X.w;
		for(int i=0;i<G[_u].size();i++){
			node Y=G[_u][i];
			int _v=Y.u,uv=Y.w;
			if(_w+uv>=dis[s][_v])continue;
			pq.push((node){_v,_w+uv});
			dis[s][_v]=_w+uv;
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)scanf("%lld%lld",&a[j],&t[j]);
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
				G[a[j]].push_back((node){a[l],t[j]+t[l]});
				G[a[l]].push_back((node){a[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)dis[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=m;i++)bfs(i);
	while(q--){
		scanf("%lld%lld",&x,&y);
		if(x>y)swap(x,y);
		printf("%lld\n",w[x]+w[y]+dis[x][y]);
	}
	return 0;
} 
