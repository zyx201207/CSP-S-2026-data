#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int mx = -1;
	int sum = 1;
	int ans = -1;
	int num = 1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		sum = sum & a[i];
		if (a[i] > mx) mx = a[i];
	}
	if (m == n){
		cout << sum;
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i] & a[j] > ans) ans = a[i] & a[j];
		}
	}
	if (m == 2){
		cout << ans;
		return 0;
	}

	cout << mx;
	return 0;
}
