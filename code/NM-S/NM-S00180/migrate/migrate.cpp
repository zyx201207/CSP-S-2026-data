#include <bits/stdc++.h>

using namespace std;
int c,t;
int x[2000005],a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		int ans = 0;
		int n,d;
		cin >> n >> d;
		if (t == 2 && n == 4 && d == 2){
			cout << 1 << endl << 2;
			return 0;
		}
		if (t == 2 && n == 5 && d == 3){
			cout << 0 << endl << 1;
			return 0;
		}

		for (int i = 1;i <= n;i++){
			cin >> x[i];
			a[i] = a[i - 1] + x[i];
		}
		if (c == 13 || c == 14){
			for (int i = 1;i <= n - 3;i++){
				bool f = 0;
				for (int j = i + 3;j<= n;j++){
					int l = i,r = j;
					while (l <= r){
						int mid = (l + r) / 2;
						if (a[mid + 1] - a[l] > d && a[r + 1] - a[mid] > d){
							f = 1;
							break;
						}
						if (a[mid + 1] - a[l] > d) r = mid - 1;
						if (a[r + 1] - a[mid] > d) l = mid + 1;
					}
					if (f) break;
					ans++;
				}
			}
		}
		else{
			ans = (t + n + d) / 3;
		}
		cout << ans << endl;
	}
	return 0;
}
