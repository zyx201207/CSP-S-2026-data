#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define endl '\n'
using namespace std;

const int MAXN=1e3+10;

int n,k,vis[MAXN],fa[MAXN],dis[MAXN][MAXN],u[MAXN],v[MAXN],ans,ds[MAXN];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void dfs(int now,int r){
	if(now>n){
		if(r==0){
			for(int i=1;i<=n;i++) fa[i]=i,ds[i]=n+1;
			for(int i=1;i<n;i++) if(vis[u[i]]&&vis[v[i]]) fa[find(u[i])]=find(v[i]);
			int num=0;
			for(int i=1;i<=n;i++) if(vis[i]&&fa[i]==i) num++;
			if(num>2) return;
			int res=0;
			for(int i=1;i<=n;i++) if(vis[i]) for(int j=1;j<=n;j++) ds[j]=min(ds[j],dis[i][j]);
			for(int i=1;i<=n;i++) res=max(res,ds[i]);
			ans=min(ans,res);
		}
		return;
	}
	if(r) vis[now]=1,dfs(now+1,r-1);
	vis[now]=0,dfs(now+1,r);
	return;
}

void mian(){
	cin>>n>>k;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<n;i++) cin>>u[i]>>v[i],dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++) dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	ans=n+1;
	dfs(1,k);
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t>>t;while(t--) mian();
	return 0;
}
