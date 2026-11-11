#include<bits/stdc++.h>
using namespace std;

const int N=502,M=500005,MN=N+M;
int w[M],k;

vector<pair<int,int>> vt[N+M];
//vt[u].first=v vt[u].second=w

void build(int u,int v,int w){
	vt[u].push_back({v,w});
	vt[v].push_back({u,w});
}

int vis[MN],dis[MN];
void dfs(int u){
	
//	printf("u=%d\n",u);
//	for(int i=1;i<=5;i++){
//		printf("dis[%d]=%d\n",i,dis[i]);
//	}
//	printf("\n");
	
	if(vis[u]){
		return;
	}
	vis[u]=1;
	for(auto v : vt[u]){
		
//		printf("u=%d v=%d\n",u,v.first);
//		for(int i=1;i<=5;i++){
//			printf("dis[%d]=%d\n",i,dis[i]);
//		}
//		printf("\n");
		
		
		dfs(v.first);
		dis[u]=min(dis[u],dis[v.first]+v.second);
	}
	return;
}

void init(int x){
	for(int i=0;i<M+N;i++){
		dis[i]=2147483647;
		vis[i]=0;
	}dis[x]=0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q,a,t,x,y;
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<M;i++){
		cin >> w[i];
	}
	for(int i=0;i<n;i++){
		cin >> k;
		for(int j=0;j<k;j++){
			cin >> a >> t;
			build(i,a+n,t);
		}
	}
	for(int i=0;i<q;i++){
		cin >> x >> y;
		init(x+n);
		dfs(x+n);
		cout << dis[y] << '\n';
	}

	
//	dis[1]=0;
//	dfs(1);
//	for(int i=1;i<=5;i++){
//		printf("dis[%d]=%d\n",i,dis[i]);
//	}
	return 0;
}
