#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>
void read(T& x)
{
	int f = x = 0, v = getchar();
	while((v != '-') && (v < '0' || v > '9')) v = getchar();
	if(v == '-') f = 1, v = getchar();
	while(v >= '0' && v <= '9') x = (x << 3) + (x << 1) + (v & 15), v = getchar();
	if(f) x = -x;
}
template <typename T>
void write(T x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x | 48);
	else write(x / 10), putchar((x % 10) | 48);
}
const int maxn = 5e5;
int n, ans;
ll m;
ll a[maxn + 5];
ll sum[maxn + 5];
int main()
{
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
	read(n), read(m);
	for(int i = 1; i <= n; ++i)
		read(a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + a[i];
	for(int i = 1; i <= n; ++i)
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if((i-mid+1) * a[i] - (sum[i] - sum[mid-1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i-l+1);
	}
	cout << ans << endl;
	return 0;
}

//5 5
//1 2 4 8 9