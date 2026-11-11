#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 5e5 + 10;
int a[N];

signed main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	bool A = true;
	for (int i = 1;i <= n;i++){
		if (a[i] != i) A = false;
	}
	bool B = true;
	int differ = a[2] - a[1];
	for (int i = 3;i <= n;i++){
		if (a[i] - a[i - 1] != differ) B = false;
	}
	if (A){
		for (int i = n;i >= 1;i--){
			int sum = (i - 1) * i / 2;
			if (sum <= m){
				cout << i;
				break;
			}
		}
		return 0;
	}
	if (B){
		for (int i = n;i >= 1;i--){
			int sum = (a[i] - differ) * i / 2;
			if (sum <= m){
				cout << i;
				break;
			}
		}
		return 0;
	}
	int full = (1 << n) - 1;
	int mx = -N;
	for (int state = 0;state <= full;state++){
		int cnt = 0;
		int temp = -10000000000000;
		for (int i = 1;i <= n;i++){
			if (state & (1 << (i - 1))){
				temp = max(temp, a[i]);
				cnt++;
			}
		}
		int cha = 0;
		for (int i = 1;i <= n;i++){
			if (state & (1 << (i - 1))){
				cha += temp - a[i];	
			}
		}
		if (cha <= m) mx = max(mx, cnt);
	} 
	cout << mx;
	
	return 0;
}
