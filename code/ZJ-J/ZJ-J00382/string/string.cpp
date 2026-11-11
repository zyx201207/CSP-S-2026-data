#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long a[N],k,st[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++) {
			k++;
			st[k] = c[i];
		}
	}
	long long sum = 0;
	for(int i = 1;i <= (k / 2);i++) {
		if(st[i] != st[k - i + 1])
		sum ++;
	}
	cout << sum << endl;
	return 0;
}//Trick||Treat!