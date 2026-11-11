#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5+10;
int n, m, c, q, d;
struct Station{
	int n, t;
	vector<pair<int, int> > con;
}s[N];

bool vis[N];

int dfs(int n, int target){
	if(n == target){
		return s[target].t;
	}
	vis[n] = 1;
	ll minn = 0x3f3f3f3f3f3f, ans = 0;
	for(int i = 0; i < s[n].con.size(); i++){
		int num = s[n].con[i].first, t = s[n].con[i].second;
		if(vis[num]) continue;
		ans = t + dfs(num, target);
		minn = min(ans, minn);
	}
	vis[n] = 0;
	return minn;
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> s[i].t;
		s[i].n = i;
	}
	int l, num, t;
	for(int i = 1; i <= n; i++){
		cin >> l;
		vector<pair<int, int> > last;
		pair<int, int> u;
		for(int j = 1; j <= l; j++){
			cin >> num >> t;
			u.first = num;
			u.second = t;
			last.push_back(u);
		} 
		for(int j = 0; j < last.size(); j++){
			for(int k = j+1; k < last.size(); k++){
				//same[last[k].first][last[j].first] = 1;
				//same[last[j].first][last[k].first] = 1;
				u.first = last[j].first;
				u.second = last[j].second + last[k].second;
				s[last[k].first].con.push_back(u);
				u.first = last[k].first;
				s[last[j].first].con.push_back(u);
			}
		}
	}
	int u_, v_;
	while(q--){
		cin >> u_ >> v_;
		cout << s[u_].t + dfs(u_, v_) << "\n";
	}
	return 0;
}
