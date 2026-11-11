#include<bits/stdc++.h>
using namespace std;
const int N=105;
int c,t;
int n,k;
int u,v;
vector<int> edge[N];
int dep[N],fa[N][25],p[N],ro[N],d[N];
int root(int x){
	return p[x]=x==p[x]?x:root(p[x]);
}
int merge(int x,int y){
	int fx=root(x),fy=root(y);
	p[fx]=fy;
}
bool check(int num){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if((1<<(i-1))&num)cnt++;
	if(cnt!=k)return 1;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		if((1<<(i-1))&num){
			for(auto v:edge[i])
				if((1<<(v-1))&num)
					merge(v,i);
		}
	cnt=0;
	memset(ro,0,sizeof(ro));
	for(int i=1;i<=n;i++){
		if((1<<(i-1))&num)
			ro[root(i)]++;
	}
	for(int i=1;i<=n;i++){
		if(ro[i])cnt++;
	}
	return cnt!=2;
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:edge[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=20;i>=0;i--)
		if(dep[fa[a][i]]>=dep[b])a=fa[a][i];
	if(a==b)return a;
	for(int i=20;i>=0;i--)
		if(fa[a][i]!=fa[b][i])
			a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);
		int maxx=(1<<(n+1)),ans=1e9;
		for(int i=0;i<maxx;i++){
			if(check(i))continue;
			memset(d,0x3f,sizeof(d));
			int mx=0;
			for(int j=1;j<=n;j++){
				if(1<<(j-1)&i)
					for(int v=1;v<=n;v++)
						d[v]=min(d[v],dis(j,v));
			}
			for(int j=1;j<=n;j++)
				mx=max(mx,d[j]);
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			edge[i].clear();
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
