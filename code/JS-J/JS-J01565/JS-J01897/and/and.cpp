#include <bits/stdc++.h>
using namespace std;
long long n,m, ans = 0;
long long a[1000009];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(m == 1){
		for(int i = 1;i <= n;i++){
			ans = max(ans, a[i]);
		}
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j)ans = max(ans, a[i]& a[j]);
			}
		}
	}
	if(m == 3){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int k = 1;k <= n;k++){
					if(i != j&&j != k&&i != k)ans = max(ans, a[i]& a[j]&a[k]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
