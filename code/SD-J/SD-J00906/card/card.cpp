#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int n;
int m;
int len;
int a[N];
int b[N];
int ans[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(m == 1){
		cout << n;
	}else{
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				b[i] = 0;
			}
			len = 0;
			for(int j = i; j <= n; j ++){
				for(int k = 1; k <= len; k ++){
					if(b[k] == a[j]){
						int nlen = k - 1;
						for(int kk = k; kk <= len; kk ++){
							b[kk] = 0;
						}
						len = nlen;
					}
				}
				b[++len] = a[j];
			}
			for(int i = 1; i <= len; i ++){
				ans[b[i]]++;
			}
		}
		for(int i = 1; i <= m; i ++){
			cout << ans[i] << " ";
		}
	}
	return 0;
}
