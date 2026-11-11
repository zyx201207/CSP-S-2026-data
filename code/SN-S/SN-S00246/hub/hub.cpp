#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t;
int n,k,cnt = 0,head[N],dfn[N],siz[N],scc[N];
struct node{
	int to,next;
}e[N<<1];
inline void add_edge(int u,int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
inline int tarjan(int x,int c){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			add_edge(u,v);
			add_edge(v,u);
		}
		cout<<k-1<<endl;
	}
	return 0;
}
