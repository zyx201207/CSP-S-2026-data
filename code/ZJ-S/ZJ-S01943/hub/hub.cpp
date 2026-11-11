#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+7;


namespace ImTrying{
	int n,k;
	vector<int>G[N];
	int s[N];
	struct edge{
		int u,v;
	};
	vector<edge>V;
	int res;
	int dis;
	bool vis[N];
	void dfs(int u,int tmp){
		if(s[u]){
			dis=min(dis,tmp);
			return ;
		}
		vis[u]=1;
		for(auto v:G[u]){
			if(v==u||vis[v]) continue;
			dfs(v,tmp+1);
		}
	}
	int check(int S){
		for(int i=1;i<=n;i++) s[i]=0;
		int sum=S;
		int cnt=0;
		while(sum) cnt+=(sum&1),sum>>=1;
		if(cnt!=k) return INT_MAX;
		cnt=0;
		sum=S;
		while(sum){
			if(sum&1) s[++cnt]=1;
			else s[++cnt]=0;
			sum>>=1;
		}
		int block=1;
		for(int i=0;i<n-1;i++){
			if(s[V[i].u]!=s[V[i].v]) block++;
			
		}
		res=0;
		for(int i=1;i<=n;i++){
			if(s[i]) continue;
			dis=INT_MAX;
			for(int j=1;j<=n;j++)vis[j]=0;
			dfs(i,0);
			res=max(res,dis);
		}
		return res;
	}
	void solve(){
		cin>>n>>k;
		if(n>40) return ;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			V.push_back({u,v});
		}
		int ans=INT_MAX;
		for(int S=0;S<(1<<n);S++){
			ans=min(ans,check(S));
		}
		cout<<ans<<"\n";
	}
	void work(){
		int c,T;
		cin>>c>>T;
		while(T--)solve();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ImTrying::work();
	return 0;
}

