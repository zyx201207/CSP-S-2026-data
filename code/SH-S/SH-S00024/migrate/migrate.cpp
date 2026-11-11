#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1114514;
int c,t,n,d,a[N];
vector<int>g[N];
int bfs(int x){
	vector<int>vis(N,0);
	vector<int>dp(N,0);
	vis[x]=1;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int o=q.front();
		q.pop();
		for(auto i : g[o]){
			if(a[i]<a[o])continue;
			if(!vis[i]){
				dp[i]=dp[o]+1;
				q.push(i);
			}
			if(dp[o]+1==dp[i])vis[i]++;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(vis[i]==2)res++;
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].erase(g[i].begin(),g[i].end());
		}
		for(int i=1;i<n;i++){
			int j=i+1;
			while(j<=n && a[j]-a[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i);
				j++;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
