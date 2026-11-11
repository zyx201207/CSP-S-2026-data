#include<bits/stdc++.h> 
using namespace std;
#define int long long
vector<int> G[2000006];
int n,k,ans=0;
bool cho[2000005];
int d[2000005];
void dfs2(int now,int fa){
	if(d[now]==-1)d[now]=d[fa]+1;
	else if(!cho[now]){
		d[now]=min(d[now],d[fa]+1);
	}
	for(auto i:G[now]){
		if(i==fa)continue;
		dfs2(i,now);
	}
}
void dfs(int now){
	if(now==n+1){
		int aa=0;
		for(int i=1;i<=n;i++){
			d[i]=-1;
			if(cho[i]){
				aa++;
				d[i]=0;
				dfs2(1,0);
			}
		}
		if(aa==k){
			for(int i=1;i<=n;i++){
				ans=max(ans,d[i]);
			}
		}
	}
	dfs(now+1);
	cho[now]=1;
	dfs(now+1);
	cho[now]=0;
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
	ans=0;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
		d[i]=-1;
	}
	dfs(1);
	
}
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	
}
/*
5 5
1 2 4 8 9
*/
