#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,T;
int w[1005];
int a[1005],t[1005];
//int x,y;
int ans;
vector<int>g[1005],p[1005];
int oo[1005][1005];
void init(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
		}
		for(int j=1;j<k;j++){
			for(int u=j+1;u<=k;u++){
				g[a[j]].push_back(a[u]);
				p[a[j]].push_back(t[u]+t[j]);
				g[a[u]].push_back(a[j]);
				p[a[u]].push_back(t[u]+t[j]);
			}
		}
	}
	return;
}
void bfs(){
	
}
void solve(){
	for(int x=1;x<m;x++){
		for(int y=x+1;y<=m;y++){
			queue<int>q;
			q.push(x);
			int v[1005];
			memset(v,0x3f,sizeof(v));
			v[x]=w[x];
			while(q.size()){
				int no=q.front();
				q.pop();
				for(int i=0;i<g[no].size();i++){
					int cost=p[no][i];
					int then=g[no][i];
					if(v[then]>v[no]+cost){
						v[then]=v[no]+cost;
						q.push(then);
					}
				}
			}
			oo[x][y]=oo[y][x]=v[y]+w[y];
		}
	}

}
void work(){
	ans=1e18;
	int i,j;
	scanf("%d%d",&i,&j);
	printf("%d\n",oo[i][j]);
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	solve();
	while(T--)work();
	return 0;
}
