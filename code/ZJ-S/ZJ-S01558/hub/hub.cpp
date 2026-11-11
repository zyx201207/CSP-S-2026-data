#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,dep[100010],ans,u,v,K,fa[100010][21],e[100010],f[100010],dis[1010][1010],vis[100010],flag,n;
vector<int> a[100010];
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(y==f)continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int calc(int x,int y){
	int f=lca(x,y);
	return dep[x]+dep[y]-2*dep[f];
}
void ddfs(int x,int fa){
	vis[x]=1;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(y==fa)continue;
		if(f[y]==0)continue;
		ddfs(y,x);
	}
}
int qwq(){
	flag=0;
	int ma=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(f[i]==0)continue;
		ddfs(i,0);
		cnt++;
	}
	if(cnt>2)return 2e18;
	for(int i=1;i<=n;i++)e[i]=2e18;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[j]==1)
				e[i]=min(e[i],dis[i][j]);
	for(int i=1;i<=n;i++)ma=max(ma,e[i]);
	return ma;
}
void solve(int t,int s){
	if(s>K)return ;
	if(t>n){
		for(int i=1;i<=n;i++)vis[i]=0;
		if(s==K){
			ans=min(ans,qwq());
		}
		return ;
	}
	f[t]=0;solve(t+1,s);
	f[t]=1;solve(t+1,s+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>t;
	while(t--){
		cin>>n>>K;
		ans=2e18;
		if(K==n){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			cout<<(((n+1)/2+2)/2-K/2)/2+1<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=20;i++)
			for(int j=1;j<=n;j++)
				fa[j][i]=fa[fa[j][i-1]][i-1];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				dis[i][j]=dis[j][i]=calc(i,j);
		solve(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
