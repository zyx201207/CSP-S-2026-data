#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
int ans[MAXN];
int sum[MAXN];
int last[MAXN];
struct to
{
	int s;
	int p;
}b[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = n; i >= 1; i--)
	{
		if(last[a[i]] == 0)
		{
			b[i].s = a[i];
			b[i].p = i + 1;
		}
		else
		{
			b[i].s = 0;
			b[i].p = last[a[i]];
		}
		last[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)sum[i] = 1;
	for(int i = 1; i <= n; i++)
		ans[b[i].s] += sum[i],
		sum[b[i].p] += sum[i];
	for(int i = 1; i <= m; i++)cout << ans[i] << ' ';
}