#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[200010];
long long ans;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i=1;i <= n;i++){
			ans = max(a[i], ans);
		}
	}else{
		if(m == n){
			ans = a[1];
			for(int i=2;i <= n;i++){
				ans = ans & a[i];
			}
		}else{
			if(m == 2){
				ans = a[1];
				for(int i=2;i < n;i++){
					for(int j=i;j <= n;j++){
						ans = max((a[i] & a[j]), ans);
					}
				}
			}else{
				if(m == n-1){
					long long sum;
					for(int i=1;i <= n;i++){
						if(i == 1){
							sum = a[2];
						}else{
							sum = a[1];
						}
						for(int j=2;j <= n;j++){
							if(j == i) continue;
							sum = sum & a[j];
						}
						ans = max(sum, ans);
					}
				}else{
					for(int i=1;i <= n;i++){
						ans = max(a[i], ans);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
