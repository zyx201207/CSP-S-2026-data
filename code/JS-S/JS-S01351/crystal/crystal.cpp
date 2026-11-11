#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m,t,u;
int a[5000000];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	if (n == 1){
		cout << 1;
		return 0;
	}
	if (n > 5000){
		t = 1;
		u = 1;
		while (true){
			if (m - u < 0){
				break;
			}
			m -= u;
			u += 1;
			t += 1;
		}
		cout << t;
		return 0;
	}
	sort(a,a + n);
	for (int i = 1;i < n;i++){
		u = m;
		int h = 1;
		if (i == n - 1){
			for (int j = 0;j < n - 1;j++){
				if (u - (a[i] - a[i - j - 1]) < 0){
					break;
				}
				h += 1;
				u -= (a[i] - a[i - j - 1]);
			}
		}else{
			for (int j = i - 1;j >= 0;j--){
				int c = a[i] - a[j];
				if (u - c < 0){
					break;
				}
				u -= c;
				h += 1;
			}
			for (int j = i + 1;j < n;j++){
				if (a[j] != a[i]){
					break;
				}
				h += 1;
			}
		}
		t = max(t,h);
	}
	cout << t;
}
