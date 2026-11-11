#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int a[N], b[N];
char c[N], d[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		b[n-i+1] = a[i];
		d[n-i+1] = c[i];
		sum += a[i];
	}
	int tot = 0;
	int i = 1, j = 1, pos = 0;
	while(pos < (sum-1)/2+1){
//		cout << pos << " " << i << "=" << a[i] << c[i] << " " << j << "=" << b[j] << d[j] << "\n";
		int mn = min(a[i], b[j]);
		if(c[i] != d[j]){
			tot += mn;
		}
		if(mn == a[i]){
			b[j] -= mn;
//			cout << "bj - " << mn << " = " << b[j] << "\n";
			i++;
		}
		else{
			a[i] -= mn;
			
//			cout << "ai - " << mn << " = " << a[i] << "\n";
			j++;
		}
		pos += mn;
	}
	cout << tot;
	return 0;
}

