#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans;
	cin >> n;
	string a;
	if (n == 1){
		cout << 0;
		return 0;
	}
	if (n == 2){
		int a1,a3;
		char a2,a4;
		cin >> a1 >> a2 >> a3 >> a4;
		if (a2 == a4){
			cout << 0;
			return 0;
		}
		ans = min(a1,a3);
		cout << ans;
		return 0;
	}
	for (int i = 1;i <= n; i++);{
		int j;
		cin >> j;
		string k;
		cin >> k;
		for (int l = 1; l <= j;l++){
			a += k;
		}
	}
	
	int m = a.size();
	
	if (m % 2 == 1){
		for (int i = m / 2 + 2,j = m / 2; i <= m; i++,j--){
			if (a[i] != a[j]){
				ans++;
			}
		}
	}
	else{
		for (int i = m / 2 + 1,j = m / 2; i <= m; i++,j--){
			if (a[i] != a[j]){
				ans++;
			}
		}
	}
	cout << ans;
}
