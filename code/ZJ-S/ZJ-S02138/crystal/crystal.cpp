#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 10;
ll n, m;
ll a[MAXN];
ll sum;
inline ll read()
{
	ll s = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-')ch = getchar();
	if(ch == '-')f = -1, ch = getchar();
	while(isdigit(ch))s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)a[i] = read();
	sort(a + 1, a + n + 1);
	int ans = 0;
	sum += a[1];
	for(int i = 1, j = 1; i <= n; i++)
	{
		while(j <= n)
		{
			j++;
			if(j > n)break;
			sum += a[j];
			ll need = a[j] * (j - i + 1) - sum;
			if(need > m)break;
		}
		ans = max(ans, j - i);
		sum -= a[i];
	}
	cout << ans << '\n';
}