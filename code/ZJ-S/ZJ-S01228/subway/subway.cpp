#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[510000],a[510000],t[510000];
long long ans,s[510];
bool b[510];
struct Info{
	int id,num;
};
vector<Info> g[510000];
void bfs(int start,int goal){
	queue<int> q;
	q.push(start);
	s[start]=w[start];
	while(q.empty()==false){
		int u=q.front();
		b[u]=true;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			if(b[g[u][i].id]==false){
				q.push(g[u][i].id);
			}
			if(s[g[u][i].id]>s[u]+g[u][i].num){
				s[g[u][i].id]=s[u]+g[u][i].num;	
				if(b[g[u][i].id]==true){
					q.push(g[u][i].id);
				}				
			}
		}
	}
	printf("%lld\n",s[goal]+w[goal]);
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
			scanf("%d%d",&a[j],&t[j]);
		}
		for(int x=1;x<=k;x++){
			for(int y=1;y<=k;y++){
				if(x==y){
					continue;
				}
				g[a[x]].push_back({a[y],t[x]+t[y]});
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=m;i++){
			s[i]=LONG_LONG_MAX;
			b[i]=false;
		}
		bfs(x,y);
	}
	return 0;
}