#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,f[100][100],ans=1e18;
bool vis[10000],use[10000];
vector<int>mp[10000];
void dfs(int u,int cnt,int x){
	if(cnt>2)return;
	bool ff=1;
	for(int i=0;i<mp[u].size();i++){
		int v=mp[u][i];
		bool flag=1;
		if(use[v])continue;
		use[v]=1;
		for(int i=0;i<mp[v].size();i++){
			if(vis[mp[v][i]])flag=0;
		}
		vis[v]=1;
		if(flag)dfs(v,cnt+1,x+1);
		else dfs(v,cnt,x+1);
		
		vis[v]=0;
		dfs(v,cnt,x);
		use[v]=0;
		ff=0;
	}
	if(x!=k)return;
	if(ff){
		int t=0;
		for(int i=1;i<=n;i++){
			int mi=1e18;
			for(int j=1;j<=n;j++){
				if(vis[j]==0)continue;
				mi=min(mi,f[i][j]);
			}
			t=max(t,mi);
		}
		ans=min(ans,t);
	}
}
void solve(){
	cin>>n>>k;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<n;i++){
		int u,v;scanf("%lld%lld",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
		f[u][v]=1;
		f[v][u]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
	use[1]=1;
	vis[1]=1;
	dfs(1,1,1);
	
	use[1]=1;
	vis[1]=0;
	dfs(1,0,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
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
*/
