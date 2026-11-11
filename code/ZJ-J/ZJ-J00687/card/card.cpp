#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define maxm 300005
vector<int>h[maxn];
int a[maxn],n,m,w[maxn],nxt[maxn],p[maxm],sz[maxn],cnt[maxm];
void dfs(int u){
	sz[u]=1;
	for(int v:h[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
	if(w[u])cnt[w[u]]+=sz[u];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i>=1;i--){
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nxt[i]==0){
			w[i]=a[i];
			h[i+1].push_back(i);
		}else{
			h[nxt[i]].push_back(i);
		}
	}
	dfs(n);
	for(int i=1;i<m;i++)printf("%d ",cnt[i]);
	printf("%d",cnt[m]);
	return 0;
}
//rp=inf,我感觉要AK了 
//我洛谷用户名ylsy2025012,UID我忘了 
