#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m,a[N],mx = 0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	if (m == 1) cout << mx;
	else if (m == n){
		for (int i = 2;i <= n;i++){
			a[i] &= a[i-1];
		}
		cout << a[n];
	}else if (m == 2){
		int k = 0;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				k = max(k,a[i] & a[j]);
			}
		}
		cout << k;
	}else{
		sort(a+1,a+n+1);
		cout << a[n - m + 1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
