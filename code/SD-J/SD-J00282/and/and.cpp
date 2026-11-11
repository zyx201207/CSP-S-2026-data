#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans;
bool f;

void dfs(int i, int dep, int now){
	if(dep == m){
		ans = max(ans, now);
		return ;
	}
	if(i == n + 1)
		return ;
	dfs(i + 1, dep, now);
	dfs(i + 1, dep + 1, (now == 0) ? a[i] : (now & a[i]));
}

bool cmp(int x, int y){
	return x > y;
}

bool check(int w){
	for(int i = 21; i >= 0; i--){
		int x = (1 << i) - 1;
		if(w == x)
			return 1;
	}
	return 0;
}

void Solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(!f && !check(a[i]))
			f = 1;
	}
	if(!f){
		sort(a + 1, a + n + 1, cmp);
		ans = a[m];
	}
	else if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++)
			ans &= a[i];
	} 
	else
		dfs(1, 0, 0);
	cout << ans << "\n";
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	while(T--)
		Solve();
	return 0;
}

