#include<bits/stdc++.h>
using namespace std;

long long a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m,ans = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 2; i <= n; i ++) {
		if(a[i] != a[i - 1]) {
			m = m - (i - 1) * (a[i] - a[i - 1]);
			if(m < 0) {
				break;
			}
			for(int j = i - 1; j >= 1; j --) {
				a[j] = a[i];
			}
		}
	}
	for(int i = 2; i <= n; i ++) {
		if(a[i] == a[i - 1]) {
			ans ++;
		}
	}
	cout << ans;
	
	return 0;
} 
