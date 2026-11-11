#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int testCase,_;
	int n,k;
	vector<int> g[1000005];
	bool chozen[1000005];
	bool vis[1000005];
	void dfs2(int now){
		if(vis[now]) return ;
		if(!chozen[now]) return ;
		vis[now] = true;
		for(auto it:g[now]){
			dfs2(it);
		}
	}
	bool check(){
		for(int i = 1;i<=n;i++) vis[i] = false;
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(chozen[i]&&!vis[i]) dfs2(i),cnt++;
		}
		return (cnt==2);
	}
	int dis[1000005];
	void dfs3(int now,int fa){
		dis[now] = min(dis[now],dis[fa]+1);
		for(auto it:g[now]){
			if(it==fa) continue;
			dfs3(it,now);
		}
	} 
	int calc(){
		for(int i = 1;i<=n;i++) dis[i] = 0x3f3f3f3f3f3f3f3f;
		dis[0] = -1;
		for(int i = 1;i<=n;i++){
			if(chozen[i]){
				dfs3(i,0);
			}
		}
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			maxn = max(maxn,dis[i]);
		}
		return maxn;
	} 
	int ans = 0x3f3f3f3f3f3f3f3f;
	void dfs(int now,int CNT){
		if(now==n+1||CNT==k){
			if(CNT==k&&check()){
//				cout<<calc()<<endl;
				ans = min(ans,calc());
			}
			return ;
		}
		dfs(now+1,CNT);
		chozen[now] = true;
		dfs(now+1,CNT+1);
		chozen[now] = false;
	} 
	void solve(){
		for(int i = 1;i<=n;i++) g[i].clear(),chozen[i] = false,vis[i] = false;
		cin>>n>>k;
		for(int i = 1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = 0x3f3f3f3f3f3f3f3f;
//		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
			return ;
//		}
//		anotherSolution::solve();
	}
	void main(){
		cin>>testCase>>_;
		while(_--) solve();
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}
/*
Can someone who see this help me analyze the time complexity of my solution to
Problem B?
My calculation result: about 3e8
But the last example took about 0.45s
Once even 0.6s
That's terrible, and d is only 2
Once d is 20, I'm afraid it'll TLE
However, I still get some points. Expectation: 92~100. 

Senior overall expectation: 100+[92,100]+[40,48]+15=[247,263]. 
*/

