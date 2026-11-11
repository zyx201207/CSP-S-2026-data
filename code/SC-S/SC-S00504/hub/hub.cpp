#include <bits/stdc++.h>
using namespace std;
struct sts{
	vector<int> f;
	void init(int n){
		f.resize(n);
		for(int i = 0; i <n;i++){
			f[i] = i;
		}
	}
	int get(int a){
		if(f[a] == a) return a;
		f[a] = get(f[a]);
		return f[a];
	}
	void con(int a, int b){
		a = get(a);
		b = get(b);
		if(a != b){
			f[a] = b;
		}
	}
};
void run(){
	int n, k;
	cin>>n>>k;
	vector<vector<int>> con(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	int ans = 10;
	for(int st = 0; st < 1<<n; st++){
		int cnt = 0;
		vector<int> a;
		for(int i = 0; i < n; i++){
			if(st & (1<<i)){
				cnt++;
				a.push_back(i);
			}
		}
		if(cnt != k) continue;
		sts ss;
		ss.init(n);
		for(auto id: a){
			for(auto jd:con[id]){
				if(upper_bound(a.begin(),a.end(),jd) - lower_bound(a.begin(),a.end(),jd)){
					ss.con(id,jd);
				}
			}
		}
		vector<bool> tmp(n);
		for(auto id: a){
			tmp[ss.get(id)] = true;
		}
		cnt = 0;
		for(auto id: tmp){
			cnt += id;
		}
		if(cnt > 2){
			continue;
		}
		queue<int> q;
		vector<int> dp(n,-1);
		int mx = 0;
		for(auto id: a){
			dp[id] = 0;
			q.push(id);
		}
		while(q.size()){
			int cur = q.front();
			q.pop();
			mx = max(mx,dp[cur]);
			for(auto id: con[cur]){
				if(dp[id] == -1){
					dp[id] = dp[cur] + 1;
					q.push(id);
				}
			}
		}
		ans = min(ans,mx);
	}
	cout<<ans<<'\n';
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin>>c>>t;
	for(int i = 0; i < t; i++){
		if(c <= 3){
			run();
		}
	}
}