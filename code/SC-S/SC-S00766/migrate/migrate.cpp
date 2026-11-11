#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int solve(vector<int> &a,int &n,int &d) {
	int ans=0;
	for(int k=1; k<=n; k++){
		queue<pair<int,int>> q;
		vector<int> vis(n+1,0);
		vector<int> cnt(n+1,0);
		q.push({k,0});
		while(!q.empty()) {
			int now=q.front().first,times=q.front().second;
			q.pop();
			if(vis[now]==0) vis[now]=times;
			if(times>vis[now]) continue;
			if(times==vis[now]) cnt[now]++;
			for(int i=now+1; i<=n; i++) {
				if(a[i]-a[now]<=d) q.push({i,times+1});
			}
		}
		for(int i=1; i<=n; i++) if(cnt[i]==2) ans++;
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		vector<int> a(n+1);
		for(int i=1; i<=n; i++) cin>>a[i];
		cout<<solve(a,n,d)<<"\n";
	}
	return 0;
}