#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q1;
int w[20005];
int x,y;
struct node {
	int to,w;
}k[505][20005];
int b[20005][21];

queue<int> q;
bool vis[20005];
unsigned long long dis[20005];
void spfa(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=1;i<=b[t][0];i++){
			int re;
			for(int j=1;j<=k[b[t][i]][0].to;j++){
				if(k[b[t][i]][j].to==t){
					re=j;
					break;
				}
			}
			for(int j=1;j<=k[b[t][i]][0].to;j++){
				if(dis[k[b[t][i]][j].to]>dis[t]+k[b[t][i]][re].w+k[b[t][i]][j].w){
					dis[k[b[t][i]][j].to]=dis[t]+k[b[t][i]][re].w+k[b[t][i]][j].w;
					if(!vis[k[b[t][i]][j].to]){
						vis[k[b[t][i]][j].to]=1;
						q.push(k[b[t][i]][j].to);
					}
				}
			}
		}
		vis[t]=0;
	}
	cout<<dis[y]+w[x]+w[y]<<"\n";
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		k[i][0]={k1,-1};
		for(int j=1;j<=k1;j++){
			int a,t;
			cin>>a>>t;
			b[a][++b[a][0]]=i;
			k[i][j]={a,t};
		}
	}
	while(q1--){
		cin>>x>>y;
		spfa();
	}
	return 0;
}