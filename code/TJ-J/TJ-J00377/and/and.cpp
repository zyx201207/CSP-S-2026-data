#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
int ans = 0;

void dfs(int cnt, int ans3, int n){
	if(cnt == m){
		ans = max(ans, ans3);
		return;
	}
	for(int i=1; i<=n; i++){
		if(cnt == 0) ans3 = a[i];
		dfs(cnt+1, (ans3 & a[i]), n);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	freopen("C:/Users/stu/Desktop/and/and1.in", "r", stdin);
	
	int n, m; cin >> n >> m;
	cin >> a[1]; ans1 = a[1]; ans2 = a[1];
	for(int i=2; i<=n; i++){
		cin >> a[i];
		ans1 = (ans1 & a[i]);
		ans2 = max(ans2, a[i]);
	}
	
	if(m == n){
		ans = ans1;
	}else if(m == 1){
		ans = ans2;
	}else{
		dfs(0, 0, n);
	}
	
	cout << ans << "\n";
	return 0;
}
