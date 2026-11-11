#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	LL c, t;
	cin>>c>>t;
	while(t--){
		LL n, d;
		cin>>n>>d;
		vector<vector<LL> > mp(n);
		vector<LL> a(n);
		for(LL i=0; i<n; i++)cin>>a[i];
		for(LL u=0; u<n; u++){
			for(LL v=0; v<n; v++){
				if(abs(a[u]-a[v])<=d)mp[u].push_back(v);
			}
		}
		LL ans=0;
		for(LL u=0; u<n; u++){
			queue<pair<LL, LL> > q;
			q.push({u, 0});
			vector<LL> cnt(n, 0);
			vector<LL> pat(n, 1e18);
			while(!q.empty()){

				pair<LL, LL> now=q.front();
				q.pop();
				for(LL ei=0; ei<mp[now.first].size(); ei++){
					LL e=mp[now.first][ei];
					if(pat[e]>now.second+1){
						pat[e]=now.second+1;
						cnt[e]=1;
					}else if(pat[e]==now.second+1){
						cnt[e]++;
											q.push({e, now.second+1});

					}else{
											q.push({e, now.second+1});

					}
				}
			}
			for(LL i=0; i<n; i++)if(cnt[i]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
