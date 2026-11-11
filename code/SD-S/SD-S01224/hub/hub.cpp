#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
struct EDGE{
	int u,v,nxt;
}edge[2000005];
int head[1000005],tot;
void add(int u,int v){
	edge[++tot]={u,v,head[u]};
	head[u]=tot;
}
int vis[1000005];
int col[1000005];
void dfs1(int x){
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(vis[v]||!col[v])continue;
		dfs1(v);
	}
}
int dfs2(int x,int fa){
	int ans=1e9;
	if(col[x])return 0;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==fa)continue;
		ans=min(ans,dfs2(v,x));
	}
	return ans+1;
}
void init(){
	for(int i=1;i<=n;i++)vis[i]=col[i]=head[i]=0;
	for(int i=1;i<=tot;i++)edge[i]={0,0,0};
	tot=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		init();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);add(v,u);
		}
		if(c==13||c==14){
			cout<<((n+1)-k*2)/8+1<<'\n';
			continue;
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int now=0,cnt=0,qwq=0;
			for(int j=1;j<=n;j++){
				if((1<<j-1)&i)col[j]=1,qwq++;
				else col[j]=0;
				vis[j]=0;
			}
			for(int j=1;j<=n;j++){
				if(col[j]&&!vis[j])dfs1(j),cnt++;
			}
			if(cnt>2||qwq!=k)continue;
			for(int j=1;j<=n;j++){
				now=max(now,dfs2(j,0));
			}
			ans=min(ans,now);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
13 1
9 3
1 2
2 3
3 4
4 5
1 6
2 7
3 8
4 9

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
*/
