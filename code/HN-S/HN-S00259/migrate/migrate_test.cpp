#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	int testCase,_;
	int n,d;
	int x[2000005];
	namespace bf{
		vector<int> g[5005];
		int dis[5005];
		int cnt[5005];
		queue<int> q;
		void bfs(int st){
			while(!q.empty()) q.pop();
			for(int i = 1;i<=n;i++) dis[i] = 0x3f3f3f3f3f3f3f3f,cnt[i] = 0;
			dis[st] = 0;
			cnt[st] = 1;
			q.push(st);
			while(!q.empty()){
				int f = q.front();
				q.pop();
				for(auto it:g[f]){
					if(dis[it]>dis[f]+1){
						cnt[it]+=cnt[f];
						dis[it] = dis[f]+1;
						q.push(it);
					}else if(dis[it]==dis[f]+1){
						cnt[it]+=cnt[f];
					}
				} 
			} 
		}
		void solve(){
			for(int i = 1;i<=n;i++) g[i].clear();
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			int ans = 0;
			bfs(1);
			int id = 0;
			for(int i = 1;i<=n;i++){
				if(cnt[i]==2) id = i;
			}
			cout<<(n-id+1)<<endl;
//			for(int i = 1;i<=n;i++){
//				bfs(i);
//				for(int j = 1;j<=n;j++){
//					if(cnt[j]==2) cout<<i<<' '<<j<<endl;
//					ans+=(cnt[j]==2);
//				}
//			}
//			cout<<ans/2<<endl;
		}
	}
	void solve(){
		cin>>n>>d;
		for(int i = 1;i<=n;i++) cin>>x[i];
//		if(n<=5000){
			bf::solve();
			return ;
//		}
	}
	void main(){
		cin>>testCase>>_;
		while(_--) solve();
	}
}
signed main()
{
	freopen("migrate4.in","r",stdin);
	freopen("migrate_test.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

