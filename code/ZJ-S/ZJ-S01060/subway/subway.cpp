#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,w[500005],l[500005],aa[1005][1005];
struct hx{
	int k;
	vector<int> P,T;
} h[505];
struct oo{
	int point;
	long long vl;
};
bool operator <(oo x,oo y){
	return x.vl > y.vl;
}
priority_queue<oo> q;
struct jg{
	int s;
	int to;
};
vector<jg> H[500005];
bool vis[500005];
void bfs(int x){
	for(int i = 1;i<=m;i++) vis[i] = 0,l[i] = 0x3f3f3f3f;
	q.push({x,0});
	int N;
	long long vl;
	while(!q.empty()){
		N = q.top().point;
		vl = q.top().vl;
		q.pop();
		if(vis[N]) continue;
		l[N] = vl;
		vis[N] = 1;//printf("jrt%d ",vl);
		for(auto it : H[N]){
			for(int i = it.to+1;i<h[it.s].k;i++){
				q.push({h[it.s].P[i] , h[it.s].T[it.to]+vl+h[it.s].T[i]});
//				printf("%d %d %d %d\n",N,i,h[it.s].P[i],h[it.s].T[it.to]+vl+h[it.s].T[i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i = 1;i<=m;i++) scanf("%d",&w[i]);
	int ppp,ttt;
	for(int i = 1;i<=n;i++){
		scanf("%d",&h[i].k);
		for(int j = 0;j<h[i].k;j++){
			scanf("%d%d",&ppp,&ttt);
			H[ppp].push_back({i,j});
			h[i].P.push_back(ppp);
			h[i].T.push_back(ttt);
		}
	}int u,v;
	if(c <= 11){
		for(int i = 1;i<=m;i++){
			bfs(i);//putchar('\n');
			for(int j = 1;j<=m;j++) aa[i][j] = l[j];
		}
		for(int i = 1;i<=qq;i++){
			scanf("%d%d",&u,&v);
			printf("%d\n",aa[u][v]+w[u]+w[v]);
		}
	}
	else{
		for(int i = 1;i<=qq;i++){
			scanf("%d%d",&u,&v);
			bfs(u);
			printf("%d\n",l[v]+w[u]+w[v]);
		}
	}
	return 0;
}
