#include <bits/stdc++.h>
using namespace std;
int C,d,n,m,w[501000],Q,ans,vis[501000],l;
struct edge{
	int u,val;
};
vector<edge> e[501000]; 
void dfs(int now,int to,int s){
	if(now==to){
		ans=min(ans,s);
		return;
	}
	if(s>=ans){
		return ;
	}
	for(int i=0;i<e[now].size();i++){
		int v=e[now][i].u,ss=e[now][i].val;
		if(vis[v]>=ss+s){
			vis[v]=ss+s;
			dfs(v,to,s+ss);
		}
	} 
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,t[1010],a[1010];
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[j]);
		}
		for(int j=1;j<=k;j++){
			scanf("%d",&t[j]);
		}		
		for(int j=1;j<=k;j++){
			for(int p=1;p<=k;p++){
				e[j].push_back((edge){a[p],t[p]+t[j]});
				e[p].push_back((edge){a[j],t[p]+t[j]});
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1e9+7;
		for(int j=1;j<=m;j++){
			vis[j]=1e9;
		}
		dfs(x,y,0);
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
} 
