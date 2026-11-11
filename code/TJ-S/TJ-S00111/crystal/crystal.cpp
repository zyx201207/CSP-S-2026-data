#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005]={0};
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	int ans = 1;
	for (int i = n;i >= 2;i--){
		int i_m = m;
		int cnt = 1;
		for (int j = i-1;j >= 1;j--){
			if (i_m >= a[i] - a[j]){
				i_m -= a[i] - a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		ans = max(ans,cnt);
	} 
	cout << ans;
	return 0;
}
