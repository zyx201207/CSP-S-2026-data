#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5+10;
int p2[35] = {1}, a[N];
vector<int> ch;
bool cmp(int a, int b){
	return a > b;
}
bool isp2(int n){
	int l = 0, r = 30, mid, ans = -1;
	while (l <= r){
		mid = (l+r)/2;
		if (p2[mid] <= n){
			l = mid+1;
			ans = mid;
		}
		else{
			r = mid-1;
		}
	}
	return (p2[ans] == n);
}
int dfs(int num){
	if (num == n){
		if (ch.size() != m) return -1;
		int ans = ch[0];
		for (int i = 1; i < ch.size(); i++){
			ans &= ch[i];
		}
		return ans;
	}
	int ans = dfs(num+1);
	ch.push_back(a[num+1]);
	ans = max(ans, dfs(num+1));
	ch.pop_back();
	return ans;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 30; i++) p2[i] = p2[i-1]*2;
	bool flag = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		flag = flag && isp2(a[i]+1);
	}
	if (flag){
		sort(a+1, a+n+1, cmp);
		int ans = a[1];
		for (int i = 2; i <= m; i++) ans &= a[i];
		cout << ans;
	}
	else cout << dfs(0);
	return 0;
}