#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int dis[N];
int fa[N],d[N];
int rt;
queue<int>q;
bool vis[N];
vector<int>ch[N];
int n,k,dep[N];
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=0;i<ch[u].size();++i){
		int v=ch[u][i];
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}
void bfs1(){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;++i){
		dis[i]=1e9;
		if(d[i]==1)q.push(i),dis[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<ch[u].size();++i){
			int v=ch[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	rt=1;
	for(int i=2;i<=n;++i){
		if(dis[i]>dis[rt])rt=i;
	}
	dfs(rt);
}
int r,sz[N];
int res=0,mx=0;
int mxdep[N],Mxdep[N],_mxdep[N];
void ins(int u,int k,int v){
	if(k>=mxdep[u]){
		Mxdep[u]=mxdep[u];
		mxdep[u]=k;
		_mxdep[u]=v;
	}else if(k>Mxdep[u])Mxdep[u]=k;
}
int calc(int u,int v){
	if(_mxdep[u]==v)return Mxdep[u];
	return mxdep[u];
}
void dfs2(int u){
	mxdep[u]=1;
	_mxdep[u]=-1;
	sz[u]=1;
	for(int i=0;i<ch[u].size();++i){
		int v=ch[u][i];
		if(v==fa[u])continue;
		if(!vis[v])continue;
		dfs2(v);
		sz[u]+=sz[v];
		ins(u,mxdep[v]+1,v);
		ins(u,Mxdep[v]+1,v);
	}
}
int jump(int u,int v,int k,int st,int c){
	if(!u)return -1;
	if(dis[u]==r+1 && !st)return -1;
	if(calc(u,v)>r-k){
		--c;
		if(!c)return -1;
	}
	int t=jump(fa[u],u,k+1,0,c);
	if(t==-1)return u;
	return t;
}
bool check(int mid){
	r=mid;
	res=mx=0;
	for(int i=0;i<=n+1;++i)vis[i]=sz[i]=mxdep[i]=Mxdep[i]=_mxdep[i]=0;
	for(int i=1;i<=n;++i){
		if(dis[i]>r)vis[i]=1,++res;
	}
	dfs2(rt);
	for(int i=1;i<=n;++i){
		if(dis[i]==r+1){
			int t=jump(i,-1,0,1,2);
			if(t==-1)continue;
			mx=max(sz[t]-sz[i],mx);
		}
	}
	res-=mx;
	return res<=k;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n+1;++i)ch[i].clear(),d[i]=dep[i]=fa[i]=dis[i]=0;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
		++d[u],++d[v];
	}
	rt=0;
	bfs1();
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)solve();
	return 0;
}

