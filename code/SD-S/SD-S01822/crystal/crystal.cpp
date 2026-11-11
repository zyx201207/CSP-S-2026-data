#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long cnt, ci, he, minn = -1;

int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//shuru
	cin >> n >> m;
	long long a[n + 1];
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	//chuli (shuzu a) 
	sort(a+1, a+1+n);
	
	/*for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++ ) {
			if (s >= m) break;
			s = j - i;
			long long c = a[j+1] - a[j];
			cnt += s * c; 
			ans += a[j];
		}
		if (s >= m) break;

	}
	
	long long R = n, l = 1;
	while (L > R){
		int mid = (L +R) / 2;
		if (a[mid] - a[mid+1] > a[mid])
	}
	*/
	
	
	
	
	
	
	
	
	
	//shuchu
	cout << m / 2;
	
	
	return 0;
}
