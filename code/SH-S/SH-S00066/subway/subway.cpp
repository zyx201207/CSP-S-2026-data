#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring> 
using namespace std;
int c,n,m,d,q,a[505][50005],t[505][50005],w[500005],k[505],x,y;
int h[50005][505],vis[500005];
struct node{
	int s,dt,tm;
};
void psh(queue<node> p,int s,int dt,int tm){
	node q;
	q.s=s;q.dt=dt;q.tm=tm;
	p.push(q);
}
int bfs(int z){
	queue<node> q;
	for (int i=1;i<=h[z][0];i++){
		psh(q,z,h[z][i],0);
	}
	vis[z]=1;
	while(!q.empty()){
		node now=q.front();
		if(now.s==y) return now.tm;
		q.pop();
		for (int i=1;i<=k[now.dt];i++){
			if(!vis[a[now.dt][i]]){
				for (int j=1;j<=h[a[now.dt][i]][0];j++)
					if(!vis[h[a[now.dt][i]][j]]){
						psh(q,a[now.dt][i],h[a[now.dt][i]][j],now.tm+t[now.dt][i]+t[h[a[now.dt][i]][j]][i]);
						vis[h[a[now.dt][i]][j]]=1;
					}
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	} 
	for (int i=1;i<=n;i++){
		cin >> k[i];
		for (int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			h[a[i][j]][++h[a[i][j]][0]]=i;
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		cin >> x >> y;
		cout << w[x]+bfs(x)+w[y] << endl;
	}
}
