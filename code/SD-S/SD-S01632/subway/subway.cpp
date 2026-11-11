#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500005],t[500005];
struct edge{
	int to,len;
};
vector<edge> e[505],z[500005];
void bfs(int x){
	for(int j=1;j<=m;j++) t[j]=INT_MAX;
	queue<int> q;
	t[x]=0;
	q.push(x);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=0;i<z[p].size();i++){
			int to=z[p][i].to;
			for(int j=0;j<e[to].size();j++){
				int tz=e[to][j].to;
				if(t[tz]>t[p]+z[p][i].len+e[to][j].len){
					t[tz]=t[p]+z[p][i].len+e[to][j].len;
					q.push(tz);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,a,t;j<=k;j++){
			scanf("%d%d",&a,&t);
			e[i].push_back((edge){a,t});
			z[a].push_back((edge){i,t});
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		bfs(x);
		printf("%lld\n",t[y]+w[x]+w[y]);
	}
	return 0;
}
