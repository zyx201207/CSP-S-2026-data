#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<pair<int,int>> g[1055];
bool vis[505][505];
int w[500005],t[500005],a[500005];
int s,e;
int minn=1e9;
void dfs(int n,int ans){
	if(n==e){
		minn=min(ans,minn);
		return ;
	}
	for(int i=0;i<g[n].size();i++){
		if(vis[n][i]==0){
			vis[n][i]=1;
			ans+=g[n][i].second;
			dfs(g[n][i].first,ans);
			vis[n][i]=0;
		}
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int cnt=m+1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j]>>t[j];
			g[a[j]].push_back({cnt,t[j]});
			g[cnt].push_back({a[j],t[j]});
			cnt++;
		}
		for(int j=1;j<x;j++){
			g[a[j]].push_back({a[j+1],0});
			g[a[j+1]].push_back({a[j],0});
		}
		
	}
	int d=cnt+1;
	for(int i=1;i<=m;i++){
		g[i].push_back({d,w[i]});
		g[d].push_back({i,w[i]});
		d++;
	}
	while(q--){
		cin>>s>>e;
		s=cnt+s;
		e=cnt+e;
		minn=1e9;
		memset(vis,0,sizeof(vis));
		dfs(s,0);
		cout<<minn<<'\n';
	}
	return 0;
}

