#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 3e5 +5;
int n, m, a[N], last[M], ans[M];
//last 出现位置   ans 桶数组记答案 
vector<int> q[M];
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n>> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		q[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i ++){
		int x = i;
		while (x <= n){
			ans[a[x]] ++;
			x = q[a[x]][q[a[x]].size() - 1] + 1;
		}
	}
	for (int i = 1; i <= m; i ++)
		cout << ans[i]<< " ";

return 0;
}
