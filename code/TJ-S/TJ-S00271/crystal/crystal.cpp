#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
int a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		cin >> a[i];		
	}
	
	sort(a, a + n);
	int tf = 0, cnt = 0, ans = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == a[i + 1]){
			cnt++;
			tf = 1;
			ans = max(ans, cnt);
		}
		else {
			cnt++;
			ans = max(ans, cnt);
			tf = 0;
			cnt = 0;
		}
	}
	
	cout << ans;
	return 0;
}











































































// m = 0, cout <<

// I FUCK CCF.
