#include <bits/stdc++.h>

using namespace std;
int a[500005];
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = 1,g = 1;
	int cha;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (i == 2) cha = a[2] - a[1];
		if (i > 2) {
			if (a[i] - a[i - 1] != cha) g = 0;
		}
		if (a[i] != i) f = 0;
	}
	int ans = 1;
	if (f){
		int p = n - 1;
		while (m >= n - p){
			ans += 1;
			m -= n - p;
			p--;
		}
	}
	else if (g){
		int p = 1;
		while (m - p * cha >= 0){
			ans += 1;
			m -= p * cha;
			p++;
		}
	}
	else{
		int mx = -1;
		int k = m;
		sort (a + 1,a + n + 1);
		for (int i = 2;i <= n;i++){
			int sum = 0;
			k = m;
			for (int j = i;j >= 1;j--){
				if (k < a[i] - a[j]) break;
				k -= a[i]- a[j];
				sum++;
			}
			mx = max(mx,sum);
		}
		ans = max(mx,ans);
	}
	cout << ans;
	return 0;
}
