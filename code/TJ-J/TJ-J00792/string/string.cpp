#include<bits/stdc++.h>
using namespace std;

long long n,a[200005],ans;
char c[200005];
string s = "0";

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
	}
	int i = 1,j = n;
	while(i <= j) {
		if(c[i] != c[j]) {
			ans += min(a[i],a[j]);
		}
		int minx = min(a[i],a[j]);
		a[i] -= minx;
		a[j] -= minx;
		if(i == j) a[i] += minx;
		if(a[i] == 0) ++i;
		if(a[j] == 0) --j; 

	}
	cout << ans;
	return 0;
}
