#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;

int a[N + 5];
int cha[N + 5];
int sum[N + 5];

int n, m;
int ans;

bool check1() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != i){
			return false;
		}
	}
	return true;
}

bool check2() {
	for (int i = 1; i < n - 1; i++) {
		if (cha[i] != cha[i + 1])
			return false;
	}
	return true;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++) {
		cha[i] = a[i + 1] - a[i];
		sum[i] = sum[i - 1] + cha[i];
	}
	sum[n] = sum[n - 1] + cha[n];
	
	if (check1()) {
		cout << m + 1;
		return 0;
	}
	
	else if (check2()) {
		cout << m / cha[1] + 1;
		return 0;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (sum[j] - sum[i - 1] <= m) {
				ans = max(j - i + 1, ans);
			}
			else {
				break;
			} 
		}
	}
	
	cout << ans;
	return 0;
}
