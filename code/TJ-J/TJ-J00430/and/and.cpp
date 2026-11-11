#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int num;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m == 2)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
	else if(m == 1)
		for(int i = 1; i <= n; i++){
			ans = max(ans, a[i]);
		}
	else if(m == 3)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					ans = max(ans, a[i] & a[j] & a[k]);
				}
			}
		}
	else if(m == 4)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					for(int p = k + 1; p <= n; p++)
						ans = max(ans, a[i] & a[j] & a[k] & a[p]);
				}
			}
		}
	else if(m == 5)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					for(int p = k + 1; p <= n; p++)
						for(int q = p + 1; q <= n; q++)
							ans = max(ans, a[i] & a[j] & a[k] & a[p]);
				}
			}
		}
	else if(m == 6)
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				for(int k = j + 1; k <= n; k++){
					for(int p = k + 1; p <= n; p++)
						for(int q = p + 1; q <= n; q++)
							for(int o = q + 1; o <= n; o++) 
								ans = max(ans, a[i] & a[j] & a[k] & a[p] & a[o]);
				}
			}
		}
	else if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++){
			ans = ans & a[i];
		}
	}
	cout << ans;
	return 0;
}

