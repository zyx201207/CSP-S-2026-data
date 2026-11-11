#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int mx = -1;
int grid[N];
int cnt = 0;
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> grid[i];
		if(i == 1) cnt = grid[i];
		else cnt = cnt & grid[i];
		mx = max(mx, grid[i]);
	}
	if(m == n){
		cout << cnt;
		return 0;
	}
	sort(grid + 1, grid + 1 + n);
	int ans = grid[1];
	for(int i = 2; i <= m; i++){
		ans = ans & grid[i];
	}
	cout << ans;
	return 0;
}
