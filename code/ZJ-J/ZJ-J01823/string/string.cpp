#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char ch[200005];
int main () {
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i ++) 
		cin >> a[i] >> ch[i];
	long long l = 1,r = n;
	while (l < r) {
		if (ch[l] != ch[r]) 
			sum += min (a[l],a[r]);
		if (a[l] < a[r])
			a[r] -= a[l],l ++;
		if (a[l] > a[r])
			a[l] -= a[r],r --;
		if (a[l] == a[r])
			l ++,r --;
	}
	cout << sum;
	return 0;
}
