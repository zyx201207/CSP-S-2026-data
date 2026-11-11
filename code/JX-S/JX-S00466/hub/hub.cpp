#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> adj[10000005];
int dep[10000005],up[10000005][21];
vector<int> leaves;
void dfs(int u,int p){
		up[u][0]=p;
		for(int i=1;i<=20;i++){
			up[u][i]=up[up[u][i-1]][i-1];
		}
		int c=0;
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(v!=p){
				c++;
				dep[v]=dep[u]+1;
				dfs(v,u);
			}
		}
		if(p!=0 and c==0) leaves.push_back(u);
}
int jump(int u,int r){
		for(int i=0)
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
