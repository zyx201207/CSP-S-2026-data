#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m; cin >> n >> m; long long a[n + 1],pow2[31]; pow2[0] = 1;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	for (int i = 1;i <= 30;i ++) pow2[i] = pow2[i - 1] * 2;
	
	bool findlast[n + 1]; long long ans = 0;
	for (int i = 1;i <= n;i ++) {findlast[i] = 1;}
	for (int i = 29;i >= 0;i --) {
		int sum = 0;
		for (int j = 1;j <= n;j ++) if((a[j] % pow2[i + 1]) / pow2[i] == 1) {
			if (findlast[j] == 1) sum ++;
		}
		
		if (sum >= m) {
			ans += pow2[i];
			for (int j = 1;j <= n;j ++) {
				if ((a[j] % pow2[i + 1]) / pow2[i] != 1 && findlast[i] == 1) findlast[i] = 0;
			}
		}
	}
	cout << ans;
}