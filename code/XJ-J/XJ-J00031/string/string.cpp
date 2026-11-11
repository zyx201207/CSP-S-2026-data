#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,q,ans = 0;
	char a[2000000];
	char e;
	cin >> n;
	long long tmp = 0;
	for (int i = 1;i <= n;i++){
		cin >> q >> e;
		for (int f = tmp + 1;f <= tmp + q;f++){
			a[f] = e;
		}
		tmp = tmp + q;
	}
	for (int i = 1;i <= tmp / 2;i++){
		if (a[i] != a[tmp - i + 1]){
			ans ++;
		}
	}
	cout << ans;
	return 0;
} 
