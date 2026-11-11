#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, mn = INT_MAX, t;
char a[N], b[N];
bool flag = true;

bool f(){
	for(int i = 0, j = m - 1; i <= t; i++, j--)
		if(a[i] != a[j]) return false;
	return true;
}

void dfs(int h, int ans){
	if(f()){
		mn = min(mn, ans);
		return ;
	}
	if(a[h] != a[m - h - 1]){
		a[h] = a[m - h - 1];
		dfs(h + 1, ans + 1);
		a[h] = b[h];
		a[m - h - 1] = a[h];
		dfs(h + 1, ans + 1);
	}
	else dfs(h + 1, ans);
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		char y;
		scanf("%d", &x);
		cin >> y;
		for(int j = 0; j < x; j++) a[m + j] = y;
		m += x;
	}
	for(int i = 0; i < m; i++) b[i] = a[i];
	int t = m / 2 + (m % 2 == 0);
	if(f()){
		cout << 0;
		return 0;
	}
	dfs(0, 1);
	cout << mn;
	return 0;
}