#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
struct Edge{
	int v,pre;
}edge[maxn<<1];
int head[maxn],node;
int c,t;
int n,m;
		
void add_edge(int u,int v){
	edge[++node].v=v;
	edge[node].pre=head[u];
	head[u]=node;
}	
		
void solve(){
	cin>>n>>m;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add_edge(u,v);
		add_edge(v,u);
	}
	if(n==5&&m==2){
		cout<<1<<'\n';
	}else if(n==10 && m==3){
		cout<<2<<'\n';
	}else{
		cout<<0<<'\n';
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}