#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q;
int to[maxn],val[maxn],dis[maxn],nxt[maxn],h[maxn],w[maxn];
bool vis[maxn];
struct node{
	int v,w;
	friend bool operator >(node a,node b){
		return a.w<b.w;
	}
};
priority_queue<node> q;

void dijkstra(){
	
}

int main(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	fro(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k*2;i++){
			
		}
	}
	return 0;
}
