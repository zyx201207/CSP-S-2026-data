#include<bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 5;
int a[N], n, m, anss; 
int m1[N], m2[N], vis[N];
void dfs(int k, int p) {
	if(p == m + 1) {
		anss = max(anss, k); 
		for(int i = 1;i <= n;i ++) vis[i] = 0;
		return ;
	}
	for(int i = 1;i <= n;i ++) {
		if(vis[i] == 0) {
			vis[i] = 1; 
			dfs(k & a[i], p + 1);
			vis[i] = 0;
		}
	}
	return ;
}
void subtask1() {
	int ans = 0;
	for(int i = 1;i <= n;i ++) ans = max(ans, a[i]);
	cout << ans;
}
void subtask2() {
	int ans = 0;
	for(int i = 1;i <= n;i ++) ans &= a[i];
	cout << ans;
}
void subtask3() {
	int ans = 0; 
	int c1 = 0, c2 = 0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] % 2 == 1) m1[++ c1] = a[i];
		else m2[++ c2] = a[i];
	}
	sort(m1 + 1, m1 + c1 + 1);
	sort(m2 + 1, m2 + c2 + 1);
	cout << max(m1[c1] & m2[c2], max(m1[c1] & m1[c1 - 1], m2[c2] & m2[c2 - 1]));
}
void subtask4() { 
    anss = 0;
    dfs(0, 0);
    cout << anss;
}
int main() { 
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	if(m == 1) subtask1();
	else if(m == n) subtask2();
	else if(m == 2) subtask3();
	else if(m <= 20 && n <= 20) subtask4(); 
	else cout << 0;
	return 0;
}
