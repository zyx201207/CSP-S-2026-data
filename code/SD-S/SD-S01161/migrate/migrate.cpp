#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int N = 2000010; 
int step, ans[2];
int n, m;
void dfs(int id, vector<int> a, int end){
	if(id == end){
		if(ans[0] == step){
			ans[1] ++;
		}
		if(ans[0] > step){
			ans[0] = step;
			ans[1] = 1;
		}
		return ;
	}
	for(int i = id + 1; i <= n; i ++){
		step ++;
		if(a[i] - a[id] <= m){
			dfs(i, a, end);
		}else{
			break;
		}
		step --;
	}
	return ;
}
void solve(int c){
	cin >> n >> m;
	vector<int> a(n + 10);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	} 
	if(c == 11 || c == 12){
		int ans1 = 0;
		int p = m / (a[2] - a[1]);
		if(p <= 1){
			cout << 0 << '\n';
			return ;
		}
//		for(int i = 1; i < p / 2; i ++){
//		}
		ans1 += n - (p + p - 1);
//		cout << p << ' ';
		cout << max(0LL, ans1) << '\n';
		return ;
	}
//	if(f){
//		cout << 
//	}
	int sum = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = i + 1; j <= n; j ++){
//			if(a[j] - a[i] <= m) continue;
			step = 0;
			ans[0] = 1145141919;
			ans[1] = 0;
			dfs(i, a, j);
			if(ans[1] == 2){
				sum = sum + 1;
//			cout << (ans[1] == 2) << ' ';
			}
//			sum += (ans[1] == 2);
		}
	}
	cout << sum << '\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t --){
		solve(c);
	}
	
	return 0;
}
//8+8=16pts
//暴力大法没发力啊 
//我不会我不会我不会我不会我不会我不会我不会我不会我不会鹅鹅鹅饿额 

