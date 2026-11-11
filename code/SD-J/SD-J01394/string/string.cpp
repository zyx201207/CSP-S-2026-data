#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long n, a[N], cnt = 0, l, r;
char b[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i] >> b[i];
	l = 1, r = n;
	while(l < r)
	{
		if(b[l] == b[r])
		{
			if(a[l] > a[r]) a[l] -= a[r], r -= 1;
			else if(a[l] < a[r]) a[r] -= a[l],l += 1;
			else l += 1, r -= 1;
		}
		else
		{
			cnt += min(a[l], a[r]);
			if(a[l] > a[r]) a[l] -= a[r], r -= 1;
			else if(a[l] < a[r]) a[r] -= a[l],l += 1;
			else l += 1, r -= 1;
		}
	}
	cout << cnt;
	return 0;
}

