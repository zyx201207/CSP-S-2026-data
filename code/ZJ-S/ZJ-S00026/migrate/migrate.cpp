#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005,MAXM=1005;
int dp[MAXN][MAXN],f[MAXN],g[MAXN],c,x[MAXN],low[MAXN],dfn[MAXN],tim=0;
struct node{
	int v,nxt;
}e[MAXM*MAXM<<1];
int p[MAXN],tot;
void addedge(int u,int v){
	e[++tot].v=v;
	e[tot].nxt=p[u];
	p[u]=tot;
}
int scc=0;
void tarjan(int u,int fa){
	low[u]=dfn[u]=++tim;
	for(int i=p[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[u]<=dfn[v]){
				scc++;
			}
		}else if(v!=fa){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c==11 || c==12){
		int del=x[2]-x[1];
		if(del>d){
			cout<<0<<endl;
			return; 
		}
		int cnt=d/del;
		if(cnt==1){
			cout<<0<<endl;
			return;
		}
		cout<<((n-1+cnt-1)/cnt)+((n-1)%cnt)<<endl;
		return;
	} 
	if(c==13 || c==14){
		
		return;
	}
	int r=2;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(x[j]-x[i]<=d){
				addedge(i,j);
			}
		}
	}
	tarjan(1,0);
	cout<<scc<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
