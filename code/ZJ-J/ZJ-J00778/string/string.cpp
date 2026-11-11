#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
char c[200010];
long long ans1, ans2, ans;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	bool flag = true;
	for(int i=1;i < n;i++){
		if(c[i] != c[i+1]){
			flag = false;
			break;
		}
	}
	if(flag){
		cout << 0;
		return 0;
	}
	if(n == 1){
		cout << 0;
	}else{
		if(n == 2){
			if(c[1] == c[2]){
				cout << 0;
			}else{
				cout << min(a[1], a[2]);
			}
		}else{
			bool f = false;
			if(n % 2 == 1){
				f = true;
			}
			for(int i=1;i <= n/2;i++){
				ans1 += a[i];
				ans2 += a[n+1-i];
			}
			if(f){
				ans = 2 * max(ans1, ans2);
			}else{
				ans = ans1 + ans2;
			}
			for(int i=1;i < n;i++){
				for(int j=i+1;j <= n;j++){
					if(c[i] == c[j] && j == n+1-i){
						ans -= 2 * min(a[i], a[j]);
					}	
				}
			}
			cout << ans / 2;
		}
	}
	return 0;
}
