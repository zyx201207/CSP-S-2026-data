#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>g[105];
int dis[105][105];
void dfs(int x,int now,int fa,int step){
	dis[x][now]=step;
	for(int v:g[now]){
		if(v==fa)continue;
		dfs(x,v,now,step+1);
	}
}
int vis[105];
int f[105];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool check(){
	vector<int>xx;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)xx.push_back(i);
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j:g[i]){
			if(upper_bound(xx.begin(),xx.end(),j)-lower_bound(xx.begin(),xx.end(),j)!=0){
				int a=find(i),b=find(j);
				if(a!=b)f[a]=b;
			}
		}
	}
	int cnt=0;
	for(int x:xx){
		if(f[x]==x)cnt++;
	}
	return cnt<=2;
}
int lans;
void dfs2(int now,int step){
	if(step==k){
		if(check()){
			vector<int>xx;
			for(int i=1;i<=n;i++){
				if(vis[i]==1)xx.push_back(i);
			}
			int ans=-1;
			for(int i=1;i<=n;i++){
				int anss=1e9;
				if(upper_bound(xx.begin(),xx.end(),i)-lower_bound(xx.begin(),xx.end(),i)!=0)anss=0;
				for(int j:xx){
					anss=min(anss,dis[i][j]);
				}
				ans=max(ans,anss);
			}
			lans=min(lans,ans);
		}
	}
	for(int i=now+1;i<=n;i++){
		vis[i]=1;
		dfs2(i,step+1);
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		lans=1e9;
		for(int i=1;i<=n;i++){
			dfs(i,i,0,0);
		}
		dfs2(0,0);
		cout<<lans<<endl;
	}
	return 0;
}
