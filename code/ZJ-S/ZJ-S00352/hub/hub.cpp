#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int f[110][110];
int p[110][100];
int a[110],b[110];
int vis[110];
int ans=1e9+20;
void dfs(int x,int fa){
	if(x>k){
		memset(vis,0,sizeof(vis));
		queue<int>q;
		int st=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&a[i]){
				st++;
				q.push(i);
				while(q.size()){
					int t=q.front();
					q.pop();
					for(int j=1;j<=n;j++)
					if(p[t][j]&&a[j]&&!vis[j])
					q.push(j),vis[j]=1;
				}	
			}
		}
		if(st>2)return ;
		int ma=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				ma=max(ma,f[b[i]][b[k]]);
		ans=min(ma,ans);
		return ;
	}
	for(int i=fa;i<=n;i++){
		a[i]=x;b[x]=i;
		dfs(x+1,i+1);
	}
}
void sol(){
	memset(f,0x1f,sizeof(f));
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin >>u>>v;
		f[u][v]=
		f[v][u]=
		p[u][v]=
		p[v][u]=1;
		f[i][i]=0;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	dfs(1,1);
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t=1,c;
	cin >>c>>t;
	while(t--)
		sol();
}
