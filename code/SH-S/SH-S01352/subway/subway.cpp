#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510000];
int k[510];
int a[510][510000];
int t[510][510000];
struct Edge{
	int to;
	int line;
	Edge(int t,int l){
		to = t;
		line = l;
	}
};
vector<Edge>edges[510000];
int dist[510000];
int bfs(int s,int t){
	queue<Edge>q;
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(j == 1) continue;
			edges[a[i][j - 1]].push_back(Edge(a[i][j],i));
		}
		edges[a[i][k[i]]].push_back(Edge(a[i][1],i));
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d",0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

