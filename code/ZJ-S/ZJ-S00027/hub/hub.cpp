#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int c,t,n,k;
vector<vector<int> >g;
int us[301],ans;
int f[301][301];
int dus[301];
void dfsz(int now){
	if(dus[now]==0)return;
	dus[now]=0;
	for(int i=0;i<g[now].size();i++)
		dfsz(g[now][i]);
}
int check(){
	int usd=0;
	for(int i=1;i<=n;i++)
		usd+=us[i],dus[i]=us[i];
	if(usd!=k)return INF;
	usd=0;
	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<dus[i]<<"\n";
		if(dus[i]){
			dfsz(i);
			usd++;
		}
	}
	if(usd>2)return INF;
	usd=0;
	for(int i=1;i<=n;i++){
		int awa=INF;
		for(int j=1;j<=n;j++)
			if(us[j])awa=min(awa,f[i][j]);
		usd=max(usd,awa);
	}
	return usd;
}
void dfs(int now){
	if(now==n+1){
		int awa=check();
//		for(int i=1;i<=n;i++)
//			cout<<us[i]<<" ";
//		cout<<"ans="<<awa<<"\n";
		if(awa!=-1)ans=min(ans,awa);
		return;
	}
	us[now]=1;
	dfs(now+1);
	us[now]=0;
	dfs(now+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		g.resize(1);
		g.resize(n+5);
		ans=INF;
		if(n<=200){
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=INF;
			for(int i=1;i<=n;i++)
				f[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			if(n<=200){
				f[u][v]=1;
				f[v][u]=1;
			}
		}
		if(c==13||c==14){
			n=(n+1)/2;
			for(int i=1;i<=n;i++){
				if(n-(i-1)-(k-1)-1-(i-1)<=2*(i-1)){
					cout<<i<<"\n";
					break;
				}
				/*
				i-1 k-1 o<=2(i-1) 1 i-1
				*/
			}
			continue;
		}
		if(n<=200){
			for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
