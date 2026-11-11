#include<iostream>
#include<queue>
using namespace std;
vector<int> ve[1000005];
bool vis[1000005],use[1000005];
int n,k,ans,dis[1000005];
void flood(int now){
//	cout << now << ' ';
	for(auto it:ve[now]){
		if(vis[it]||!use[it])continue;
		vis[it]=1;
		flood(it);
	}
}
void dfs0(int step,int cnt){
	if(cnt==k){
		int cc=0;
		for(int i = 1; i <= n; i++)
			if(!vis[i]&&use[i]){
				cc++;
				vis[i]=1;
				flood(i);
//				cout << endl;
			}
//		cout << "-----------------\n";
		if(cc>2){
			for(int i = 1; i <= n; i++)dis[i]=vis[i]=0;
			return;
		}
		queue<int> q;
		for(int i = 1; i <= n; i++)
			if(use[i]){
				dis[i]=1;
				q.push(i);
			}
		int tt=1;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(auto it:ve[t]){
				if(dis[it])continue;
				dis[it]=dis[t]+1;
				tt=max(tt,dis[it]);
				q.push(it);
			}
		}
//		if(tt-1<=ans){
//			for(int i = 1; i <= n; i++)
//				if(use[i])
//					cout << i << ' ';
//			cout << tt-1 << endl;
//		}
		ans=min(ans,tt-1);
		for(int i = 1; i <= n; i++)dis[i]=vis[i]=0;
		return;
	}
	if(step>n)return;
	dfs0(step+1,cnt);
	use[step]=1;
	dfs0(step+1,cnt+1);
	use[step]=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		ans=1000000000;
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		dfs0(1,0);
		cout << ans << '\n';
		for(int i = 1; i <= n; i++)ve[i].clear();
	}
	return 0;
}
