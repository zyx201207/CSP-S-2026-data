#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,t;

vector<int> G[200010];
int n,k;


int res=0;
int ans=10000000000;

int f[200010];
int v[200010];

int d[200010];
void dfs(int x,int F){
	f[x]=1;
	for(int i=0;i<(int)G[x].size();i++){
		int y=G[x][i];
		if(v[y]==0||y==F)continue;
		dfs(y,x);
	}
}
void dfs1(int x,int F,int w){
	d[x]=min(w,d[x]);
	for(int i=0;i<(int)G[x].size();i++){
		int y=G[x][i];
		if(y==F)continue;
		dfs1(y,x,w+1);
	}
}



void ddfs(int x,int F){
	res++;
	v[x]=1;
	if(res==k){
		int sum=0;
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=1;i<=n;i++)d[i]=100000000;
		for(int i=1;i<=n;i++){
			if(f[i]==0&&v[i]==1){
				dfs(i,0);sum++;
			}
		}
		if(sum<=2){
			int rrr=0;
			for(int i=1;i<=n;i++){
				if(v[i])dfs1(i,0,0);
			}
			for(int i=1;i<=n;i++)rrr=max(rrr,d[i]);
			ans=min(rrr,ans);
		}
	}
	else {
		for(int i=0;i<(int)G[x].size();i++){
			int y=G[x][i];
			if(y==F)continue;
			ddfs(y,x);
		}
	}
	res--;
	v[x]=0;
	
	for(int i=0;i<(int)G[x].size();i++){
		int y=G[x][i];
		if(y==F)continue;
		ddfs(y,x);
	}
	
}



signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=100000000;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v),G[v].push_back(u);
		}
		ddfs(1,0);
		cout<<ans<<'\n';
	}
	
	
	
	
	
	return 0;
}


