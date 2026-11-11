#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL N = 2e5 + 5;
int n, m, a[N], mx, ans;
bool flg;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		/*
		for(int j = 1;j < i-1;j++){
			mx = max(mx, a[j] & a[i]);
		}
		*/
	}
	sort(a + 1, a + n + 1);
	ans = a[n];
	for(int i = 1; i < m;i++){
		ans &= a[n - i];
	}
	cout << ans;
	
	return 0;
}
