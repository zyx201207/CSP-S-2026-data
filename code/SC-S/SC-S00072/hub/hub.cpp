#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=4000+5,INF=1e9;
ll ID,T,n,m,dis[MAXN][MAXN],dis2[MAXN],ans,ansx,ansy,mx,mn,book[MAXN],lst[MAXN];
vector<ll>a[MAXN];
void dfs(ll u,ll fa,ll zu,ll step){
	dis[zu][u]=step;
	for(int i=0;i<a[u].size();i++){
		ll v=a[u][i];
		if(v!=fa)dfs(v,u,zu,step+1);
	}
}
ll bfs(ll S){
	queue<ll>q;
	for(int i=1;i<=n;i++)lst[i]=0;
	lst[S]=S;
	q.emplace(S);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		if(book[u])return lst[u];
		for(int i=0;i<a[u].size();i++){
			ll v=a[u][i];
			if(!lst[v]){
				lst[v]=u;
				q.emplace(v);
			}
		}
	}
}
void bfs2(){
	queue<ll>q;
	for(int i=1;i<=n;i++){
		if(book[i]){
			dis2[i]=0;
			q.emplace(i);
		}else dis2[i]=INF;
	}
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(int i=0;i<a[u].size();i++){
			ll v=a[u][i];
			if(dis2[v]>dis2[u]+1){
				dis2[v]=dis2[u]+1;
				q.emplace(v);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ID>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)a[i].clear(),book[i]=0;
		for(int i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(int i=1;i<=n;i++)dfs(i,0,i,0);
		mn=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mx=0;
				for(int k=1;k<=n;k++)mx=max(mx,min(dis[i][k],dis[j][k]));
				if(mx<=mn){
					mn=mx;
					ansx=i,ansy=j;
				}
			}
		}
		for(int i=1;i<=n;i++)dis2[i]=min(dis[ansx][i],dis[ansy][i]);
		book[ansx]=book[ansy]=1;
		for(int i=1;i<=m-2;i++){
			mx=0;
			ll w=0;
			for(int j=1;j<=n;j++){
				if(dis2[j]>mx){
					mx=dis2[j];
					w=j;
				}
			}
			w=bfs(w);
			book[w]=1;
			bfs2();
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dis2[i]);
		cout<<ans<<'\n';
	}
	return 0;
}