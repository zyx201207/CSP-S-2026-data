#include<bits/stdc++.h>
using namespace std;
long long pre[1000010];
int C,D,Q,n,m,K[510],tmp,top[1000010],fa[1000010],siz[1000010],son[1000010],dep[1000010],W[500010],tmpp,f[1000010];
pair<int,pair<int,int>>e[1000010];
vector<pair<int,int>>E[1000010];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
inline void dfs1(int x){
	siz[x]=1;
	top[x]=x;
	dep[x]=dep[fa[x]]+1;
	for(int i=0,R=E[x].size();i<R;++i){
		int v=E[x][i].first,w=E[x][i].second;
		if(v==fa[x])
			continue;
		fa[v]=x;
		pre[v]=pre[x]+w;
		dfs1(v);
		if(siz[son[x]]<siz[v])
			son[x]=v;
		siz[x]+=siz[v];
	}
}
inline void dfs2(int x){
	if(son[x]){
		top[son[x]]=top[x];
		dfs2(son[x]);
	}
	for(int i=0,R=E[x].size();i<R;++i){
		int v=E[x][i].first,w=E[x][i].second;
		if(v==fa[x]||v==son[x])
			continue;
		dfs2(v);
	}
}
inline long long query(int x,int y){
	long long ans=W[x]+W[y]+pre[x]+pre[y];
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
	if(dep[y]<dep[x])
		swap(x,y);
	return ans-2*pre[x];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>D>>Q;
	for(register int i=1;i<=m;++i)
		cin>>W[i],f[i]=i;
	tmp=m;
	for(register int i=1;i<=n;++i){
		cin>>K[i];
		for(register int j=0,lst=0;j<K[i];++j){
			int a,t;
			cin>>a>>t;
			++tmp;
			f[tmp]=tmp;
			e[++tmpp]={t,{a,tmp}};
			if(lst)
				e[++tmpp]={0,{lst,tmp}};
			lst=tmp;
		}
	}
	sort(e+1,e+1+tmpp);
	for(int i=1,cnt=tmp-1;cnt;++i){
		int u=e[i].second.first,v=e[i].second.second,w=e[i].first;
		if(find(u)==find(v))
			continue;
		f[find(u)]=find(v);
		E[u].push_back({v,w});
		E[v].push_back({u,w});
		--cnt;
	}
	dfs1(1);
	dfs2(1);
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<query(x,y)<<'\n';
	}
	return 0;
}
