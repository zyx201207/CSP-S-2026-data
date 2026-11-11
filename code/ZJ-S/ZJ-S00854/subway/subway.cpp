#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define N 500010
#define inf 1e18
using namespace std;
const ll danger=2e8;
ll read(){
	int f=0;
	ll ans=0;
	char c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10ll+c-'0';
		c=getchar();
	}
	if(f){
		ans*=-1;
	}
	return ans;
}
int c,n,d,vis[N];
ll down[N],dis[N],m,q;
vector<pii>dot[N],g[N],xian[N];
struct ques{
	int s,t,id;
	ll ans;
}qu[N];
bool cmp(ques a,ques b){
	return a.s<b.s;
}
bool cmp1(ques a,ques b){
	return a.id<b.id;
}
void bfs(int s,int t){
	queue<int>q;
	q.push(s);
	dis[s]=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//printf("%d ------",u);
		for(int i=0;i<xian[u].size();i++){
			int x=xian[u][i].fi;
			ll y=xian[u][i].se;
			if(vis[x]){
				continue;
			}
			dis[u]+=y;
			for(int j=0;j<dot[x].size();j++){
				int v=dot[x][j].fi;
				ll w=dot[x][j].se;
				if(v==u){
					continue;
				}
				dis[v]=dis[u]+w;
				if(v==t){
					return;
				}
				q.push(v);
			}
			dis[u]-=y;
			vis[x]=1;
		}
	}
}
void dijkstra(int s){
	priority_queue<pii>q;
	q.push(mp(0,s));
	for(int i=1;i<=m;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].fi;
			ll w=g[u][i].se;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(mp(-dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		down[i]=read();
	}
	for(int i=1;i<=n;i++){
		ll k=read();
		for(int j=1;j<=k;j++){
			int x=read();
			ll a=read();
			dot[i].pb(mp(x,a));
			xian[x].pb(mp(i,a));
		}
		if(k*k*n>=danger){
			continue;
		}
		for(int j=0;j<k;j++){
			for(int l=j+1;l<k;l++){
				int u=dot[i][j].fi,v=dot[i][l].fi;
				ll w=dot[i][j].se+dot[i][l].se;
				g[u].pb(mp(v,w));
				g[v].pb(mp(u,w));
	//			printf("%d %d %lld\n",u,v,w);
			}
		}
	}
	if(q*m>=danger||m*m>=danger){
		while(q--){
			int s=read(),t=read();
			bfs(s,t);
			printf("%lld\n",dis[t]+down[s]+down[t]);
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		qu[i].s=read(),qu[i].t=read();
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,cmp);
	for(int i=1;i<=q;i++){
		int s=qu[i].s,t=qu[i].t;
		if(s!=qu[i-1].s){
			dijkstra(s);
		}
	//	for(int i=1;i<=m;i++){
	//		printf("%d %lld\n",i,dis[i]);
	//	}
		qu[i].ans=dis[t]+down[s]+down[t];
	}
	sort(qu+1,qu+q+1,cmp1);
	for(int i=1;i<=q;i++){
		printf("%lld\n",qu[i].ans);
	}
	return 0;
}