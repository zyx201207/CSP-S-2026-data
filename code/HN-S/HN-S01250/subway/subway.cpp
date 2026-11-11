#include<bits/stdc++.h>
using namespace std;
struct st{
	int to,next,va;
} edge[100010];
int head[100010];
int n,m,d,q,c,cnt;
int a[500010];
void add(int u,int v,int w){
	edge[++cnt].next=head[u];
	edge[cnt].va=w;
	edge[cnt].to=v;
	head[u]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> a[i];
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++) head[i]=-1;
		while(n--){
			int h;
			cin >>h;
			if(h==1) cin >> h >> h;
			else{
				int u,v,w1,w2;
				cin >> u >> w1 >> v >> w2;
				add(u,v,w1+w2);
				add(v,u,w1+w2);
			}
		}
		while(q--){
			int x,y;
			cin >>x >> y;
			queue<int> q;
			int vis[500010];
			for(int i=1;i<=m;i++) vis[i]=10000000;
			q.push(x);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=head[u];i!=-1;i=edge[i].next){
					if(vis[u]+edge[i].va<vis[edge[i].to]){
						q.push(edge[i].to);
						vis[edge[i].to]=vis[u]+edge[i].va;
					}
				}
			}
			cout << vis[y] << endl;
		}
	}
	return 0;
} 
