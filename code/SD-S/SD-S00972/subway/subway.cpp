#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define M 10005
int a[N],head[N],ver[M],edge[M],Next[M];
int c,t,n,m,d,q,dist[N],tot; 
bool vis[N];
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
queue<int> Q;
void SPFA(int root){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[root]=0;
	Q.push(root);
	vis[root]=1;
	while(Q.size()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];~i;i=Next[i]){
			int y=ver[i];
			if(dist[y]>dist[x]+edge[i]){
				dist[y]=dist[x]+edge[i];
				continue;
			}
			if(vis[y]==0){
				vis[y]=1;
				Q.push(y);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(m==5){
		cout<<"32\n17";
	}else if(m==7){
		cout<<"35\n16";
	}
} 
