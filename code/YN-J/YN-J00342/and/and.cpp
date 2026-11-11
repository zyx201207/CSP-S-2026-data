#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long n, m, a[N], b[N];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);
	long long flag = 1;

	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int sum=n;
		for(int i = n-1;i>=1;i--){
			sum&=i;
		}
		cout<<sum;
		return 0;
	}
	sort(b + 1, b + 1 + flag);
	long long cnt = 0;

	for (long long i = flag; i >= flag - m; i--) {

		cnt += b[i];
	}

	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
