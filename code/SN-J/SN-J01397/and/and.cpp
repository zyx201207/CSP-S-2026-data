#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f(int x){
	while (x > 0){
		if (x % 2 != 0 && x != 1) return false;
		x /= 2;
	}
	return true;
}
bool p(){
	for (int i = 1; i <= n; i++){
		if (!f(a[i] + 1)){
			return false;
		}
	}
	return true;
}
void fj(int x){
	while (x > 0){
	    cout << x % 2;
		x /= 2;
	} 
	cout << "\n";
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; i++){
		fj(a[i]);
	}
	if (m == 1){
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans << "\n";
		return 0; 
	}
	if (m == n){
		int ans = a[1];
		for (int i = 1; i <= n; i++) ans = ans & a[i];
		cout << ans << "\n";
		return 0;
	}
	if (m == 2){
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				ans = max(a[i] & a[j], ans);
			}
		}
		cout << ans << "\n";
		return 0;
	}
	if (p()){
		int ans = a[n];
		for (int i = n; i >= n - m + 1; i--){
			ans = ans & a[i];
		}
		cout << ans << "\n";
	    return 0;
    }
    if (m == n - 1){
    	int n_ans = 0;
    	int ans = a[1];
    	for (int i = 1; i <= n; i++){
    		ans = a[1];
    		for (int j = 1; j <= n; j++){
    			if (i == j) continue;
    			if (i == 1 && j == 2) ans = a[2]; continue;
    			ans = ans & a[j];
			} 
			n_ans = max(n_ans, ans);
		}
		cout << n_ans << "\n";
		return 0;
	}
	return 0;
}
