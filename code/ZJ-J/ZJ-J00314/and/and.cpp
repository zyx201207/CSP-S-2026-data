#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m, a[N], b[N], mm, book[N];
void dfs(int step){
	if(step > m){
		int x = b[1];
		for(int i = 2; i < step; i ++){
			x = x&b[i];
//			cout << x << " ";
		}
//		cout << "#" << x;
		mm = max(mm, x);
		return;
	}
	for(int i = 1; i <= n; i ++){
		if(book[i] == 0){
			b[step] = a[i];
			book[i] = 1;
			dfs(step+1);
			book[i] = 0;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ma = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	if(n == m){
		int x = a[1];
		for(int i = 2; i <= n; i ++){
			x = x&a[i];
		}
		cout << x;
		return 0;
	}
	if(m == 1){
		cout << ma;
		return 0;
	}
	dfs(1);
	cout << mm;
	return 0;
}