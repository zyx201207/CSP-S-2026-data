#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
ll c,n,m,d,q,w[M];
ll read(){
	ll num=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		num=num*10+(s^48);
		s=getchar();
	}return num*f;
}
ll mp[N][N];
array<ll,2> f[M][25];
int id[M]={0};
ll dis[N],ln[N][N];
bool vis[2*N]={0};
void dijstrla(int s){
	memset(dis,63,sizeof(dis));
	priority_queue<array<ll,2>>q;
	while(!q.empty())q.pop();
	dis[s]=0;
	q.push(array<ll,2>{0,s});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		auto nw=q.top();
		q.pop();
		int u=nw[1];
		if(vis[u])continue;
		vis[u]=1;
		for(int v=1;v<=n;v++){
			if(vis[v]||mp[u][v]>1e10)continue;
			if(dis[v]>dis[u]+mp[u][v]){
				dis[v]=dis[u]+mp[u][v];
				q.push(array<ll,2>{-dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ln[s][i]=dis[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}int cnt=0;
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			ll a=read(),t=read();
			cnt++;
			f[a][++id[a]]=array<ll,2>{i,t};
		}
	}
	memset(mp,63,sizeof(mp));
	for(int i=1;i<=m;i++){
		for(int nx=1;nx<=id[i];nx++){
			auto x=f[i][nx];
			for(int ny=1;ny<=id[i];ny++){
				auto y=f[i][ny];
				if(x==y)continue;
				mp[x[0]][y[0]]=min(mp[x[0]][y[0]],x[1]+y[1]);
				mp[y[0]][x[0]]=min(mp[y[0]][x[0]],x[1]+y[1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijstrla(i);
	}
	while(q--){
		ll x=read(),y=read(),ans=LONG_LONG_MAX;
		for(int nx=1;nx<=id[x];nx++){
			auto i=f[x][nx];
			for(int ny=1;ny<=id[y];ny++){
				auto j=f[y][ny];
				ans=min(ans,w[x]+w[y]+ln[i[0]][j[0]]+i[1]+j[1]);
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
