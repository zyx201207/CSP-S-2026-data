#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int n, m;
bool ch[N];
long long dfs(int step, long long x){
	if(step == 0)return x;
	long long res = 0;
	for(int i = 1; i <= n; i++){
		if(ch[i]) continue;
		if(a[i] < res) continue;
		ch[i] = 1;
		res = max(dfs(step - 1, x & a[i]), res);
		ch[i] = 0;
	}
	return res;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	cout << dfs(m, (1LL << 40) - 1LL);
	return 0;
}
