#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T;
	cin >> c >> T;
	while(T--){
		int n, d;
		cin >> n >> d;
		vector<int> x(n+1);
		for(int i=1;i<=n;++i){
			cin >> x[i];
		}
		if(c==11 || c==12){
			int D=x[2]-x[1];
			int ans=0;
			if(d>=D*2 && d<D*3){
				cout << n-3 << endl;
			}else{
				cout << 0 << endl;
			}
			continue;
		}
		int u, v;
		pair<int, int> ans = {1e9, 0};
		function<void(int, int)> dfs = [&](int p, int cnt){
			if(cnt>ans.first) return;
			if(p==v){
				if(cnt<ans.first){
					ans.first=cnt, ans.second=1;
				}else if(cnt==ans.first){
					ans.second++;
				}
			}
			for(int i=p+1;i<=v;++i){
				if(x[p]+d>=x[i]){
					dfs(i, cnt+1);
				}
			}
		};
		int num=0;
		for(u=1;u<=n;++u){
			for(v=u+1;v<=n;++v){
				dfs(u, 0);
				if(ans.second==2){
					++num;
				}
				ans={1e9, 0};
			}
		}
		cout << num << endl;
	}
	return 0;
}