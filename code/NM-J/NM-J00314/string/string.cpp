#include <bits/stdc++.h>

using namespace std;
int n;
string a[2000005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	int sum = 1,ans = 0;
	for (int i = 1;i <= n;i++){
		long long u;
		string v;
		cin >> u >> v;
		for (int j = sum;j <= sum + u;j++){
			a[j] = v;
		}
		sum += u;
	}
	for (int i = 1;i <= (sum - 1) / 2;i++){
		if (a[i] != a[sum - i]) ans++;
	}
	cout << ans;
	return 0;
}
