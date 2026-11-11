#include<bits/stdc++.h>
using namespace std;

long long n, m, c, ma, ans, a[200010], d[200010], b[200010][40]; 

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		long long t = a[i], l = 0;
		while(t){
			b[i][++l] = (t & 1);
			t >>= 1;
		}
		ma = max(ma, l);
	}
	bool flag = true;
	for(int j = ma; j >= 1 && flag; j--){
		long long t = 0;
		for(int i = 1; i <= n; i++){
			if(b[i][j] == 1){
				t++;
			}
		}
		if(t < m){
			continue;
		}
		for(int i = 1; i <= n; i++){
			if(b[i][j] == 0){
				if(d[i] == 0){
					c++;
					if((c + m) == n){
						flag = false;
						break;
					}
				}
				d[i] = 1;
			}
		}
	}
	ans = -1;
	for(int i = n, t = 0; t < m; i--){
		if(!d[i]){
			if(ans == -1){
				ans = a[i];
			}else{
				ans &= a[i];
			}
			t++;
		}
	}
	cout << ans << "\n";
	return 0;
}
