#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,p,st,en,ans,sum;
int w[500005];
vector<pair<int,int>> line[505];
vector<pair<int,int>> node[500005];
map<int,int> tn,tl;
void dfs(int now,int dp){
	if(dp==0&&now==en){
		ans=min(ans,sum);
		return;
	}
	else if(dp==0){
		if(tn[now]) return;
		tn[now]=1;
		for(auto it:node[now]){
		    if(tl[it.first]==0){
		    	sum+=line[it.first][it.second].second;
		    	dfs(it.first,1);
		    	tl[it.first]=0;
		    	sum-=line[it.first][it.second].second;
			}
		}
	}
	else{
		if(tl[now]) return;
		tl[now]=1;
		for(auto it:line[now]){
		    if(tn[it.first]==0){
		    	sum+=it.second;
		    	dfs(it.first,0);
		    	tn[it.first]=0;
		    	sum-=it.second;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) line[i].push_back({0,0});
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int u,v;
			cin>>u>>v;
			node[u].push_back({i,j});
			line[i].push_back({u,v});
		}
	}
	while(p--){
		tn.clear(),tl.clear();
		ans=2e18,sum=0;
		cin>>st>>en;
		dfs(st,0);
		cout<<ans+w[st]+w[en];
	}
	return 0;
}

