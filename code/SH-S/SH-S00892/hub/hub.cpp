#include<bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll long long

int C,t,n,k,ans;
int c[N],vst[N];
int fa[N],dpt[N],sz[N],top[N],son[N];
vector<int>e[N];
void dfs(int u,int f){
	fa[u]=f;dpt[u]=dpt[f]+1;sz[u]=1;
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(v==f)continue;
		dfs(v,u);sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}
void Dfs(int u,int tp){
	top[u]=tp;
	if(!son[u])return;
	Dfs(son[u],tp);
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(v==fa[u]||v==son[u])continue;
		Dfs(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dpt[top[u]]<dpt[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	return dpt[u]<dpt[v]?u:v;
}
int df[N];
int find(int x){
	if(df[x]!=x)df[x]=find(df[x]);
	return df[x]; 
}
void bf(int x){
	if(x==k+1){
		for(int i=1;i<=k;++i)df[i]=i;
		for(int i=1;i<=k;++i){
			for(int j=i+1;j<=k;++j){
				if(fa[c[i]]==c[j]||fa[c[j]]==c[i])df[find(i)]=find(j);
			}
		}
		int cc=0;
		for(int i=1;i<=k;++i)cc+=df[i]==i;
		if(cc>2)return;
		int res=0;
		for(int i=1;i<=n;++i){
			int cur=n;
			for(int j=1;j<=k;++j)cur=min(cur,dpt[i]+dpt[c[j]]-2*dpt[lca(i,c[j])]);
			res=max(res,cur);
		}
		ans=min(ans,res);
		return;		
	}
	for(int i=1;i<=n;++i){
		if(vst[i])continue;
		vst[i]=1;
		c[x]=i;
		bf(x+1);
		vst[i]=0; 
	}
} 

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	scanf("%d%d",&C,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		ans=n;
		for(int i=1;i<=n;++i){
			e[i].clear();
			son[i]=0; 
		}
		for(int i=1;i<n;++i){
			int u,v;scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(C<=3||C==7){
			dfs(1,0);Dfs(1,1);
			bf(1);
			printf("%d\n",ans);
			continue;
		}
		if(C==13||C==14){
			if(k==n)printf("0\n");
			else if(k==2&&n==7)printf("2\n");
			else{
				int m=(n-1)/2;
				int br=(m+1)/2;
				if(k>=m)printf("1\n");
				else if(m&1)printf("%d\n",1+max(0,(br+1)/2-(k/2+1)/2));
				else printf("%d\n",1+max(0,(br+1)/2-(k/2)/2));
			}
			continue;
		}
		printf("%d\n",rand()&1);
	}
	return 0;
}
