#include<bits/stdc++.h>
using namespace std;
int c,t,s;
vector<int>g[2000006];
bool vis[2000006];
void dfs(int u,int r,int d){
	if(d>r){
		s++;
		d=0;
	}
    vis[u]=1;
    for(int v:g[u])
    	if(!vis[v])
    		dfs(v,r,d+1);
    vis[u]=0;
    return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2,p=n;
			for(int i=1;i<n;i++){
                s=0;
				dfs(i,mid,1);
				p=min(p,s);
			}
			if(p>k) l=mid+1;
			else r=mid;
		}
		printf("%d\n",r);
	}
	return 0;
}
