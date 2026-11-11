#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500505],k[500505],fa[500505],dep[500505],p[500505][35],dst[500505];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;
vector<pair<int,int> >G[500505];
int read(){
	int num=0;
	char c;
	while((c=getchar())&&'0'<=c&&c<='9'){
		num=num*10+(c-'0');
	}
	return num;
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void dfs(int now,int fa){
	dep[now]=dep[fa]+1;
	p[now][0]=fa;
	for(int i=1;i<=20;i++){
		p[now][i]=p[p[now][i-1]][i-1];
	}
	for(int i=0;i<G[now].size();i++){
		if(G[now][i].first!=fa){
			dst[G[now][i].first]=dst[now]+G[now][i].second;
			dfs(G[now][i].first,now);
		}
	}
}
void kruskal(){
	int cnt=0;
	while(cnt<m-1){
		int w=pq.top().first,u=pq.top().second.first,v=pq.top().second.second;
		pq.pop();
		int a=find(u),b=find(v);
		if(a!=b){
			G[u].push_back({v,w});
			G[v].push_back({u,w});
			fa[b]=a;
			++cnt;
		}
	}
}
int lca(int a,int b){
	if(dep[a]>dep[b]){
		int t=a;
		a=b;
		b=t;
	}
	if(dep[a]!=dep[b]){
		for(int i=20;i>=0;i--){
			if(dep[p[b][i]]>dep[a]){
				b=p[b][i];
			}
		}
		b=p[b][0];
	}
	if(a==b){
		return a;
	}
	else{
		for(int i=20;i>=0;i--){
			if(p[a][i]!=p[b][i]){
				a=p[a][i];
				b=p[b][i];
			}
		}
		return p[a][0];
	}
}
int count(int a,int b){
	return dst[a]+dst[b]-2*dst[lca(a,b)]+w[a]+w[b];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		fa[i]=i;
	}
	for(int i=m+1;i<=m+n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a,t;
			a=read(),t=read();
			pq.push({t,{a,m+i}});
		}
	}
	m+=n;
	kruskal();
	dfs(1,0);
	while(q--){
		int x,y;
		x=read(),y=read();
		printf("%lld",count(x,y));
		putchar('\n');
	}
	return 0;
}
