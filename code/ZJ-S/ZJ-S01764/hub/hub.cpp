#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int fa[MAXN],dis[MAXN],vis[MAXN];
int head[MAXN],tot,c,t,n,k;
struct edge{
	int to,nxt;
}e[MAXN<<1];
void clear(){
	for(int i=1;i<=tot;i++){
		e[i]={0,0};
	}
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
}
void add(int u,int v){
	e[++tot].to=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
void dfs(int u,int from){
	fa[u]=from;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==from)continue;
		dis[v]=dis[u]+1;
		if(dis[v]>dis[c])c=v;
		dfs(v,u);
	}
}
void dp(int u,int from){
	dis[u]=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==from)continue;
		dp(v,u);
		dis[u]=max(dis[v]+1,dis[u]);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
		dis[c]=0;
		dfs(c,0);
		int d=dis[c];
		int ed=c;
		while(ed){
			if(dis[ed]<=dis[c]/2){
				break;
			}
			ed=fa[ed];
		}
		dp(ed,0);
		priority_queue<pair<int,int> >q;
		for(int i=head[ed];i;i=e[i].nxt){
			int v=e[i].to;
			q.push({-dis[v],v});
		}
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			vis[u]=1;
			k--;
			if(k==0){
				break;
			}
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].to;
				if(vis[v])continue;
				q.push({-dis[v],v});
			}
		}
		int ans=0;
		while(!q.empty()){
			ans+=-q.top().first;
			q.pop();
		}
		cout<<ans<<"\n";
	}
}
/*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5 
3 6
3 7
3 8
7 9
9 10

out:
1
2

When I was typing the words dbout the fourth problem,I suddenly felt
everything is supported me to finish it.But things went uneasily.
So,with the daydream I had made,let the unfinished things be the most unforgettable memories; 
*/ 
