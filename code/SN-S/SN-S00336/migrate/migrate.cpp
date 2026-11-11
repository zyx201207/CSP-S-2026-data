// 西安市铁一中学 王正清和 SN-S00336
#include<bits/stdc++.h>
#define fir first
#define sec second
#define mkp make_pair
#define ll long long
using namespace std;
int byx, aqx;

const int maxn = 2000000;
int n, L[maxn + 10], R[maxn + 10], A[maxn + 10], B[maxn + 10];
int FA[maxn + 10], FB[maxn + 10], GA[maxn + 10], GB[maxn + 10], HA[maxn + 10], HB[maxn + 10];
ll d, X[maxn + 10];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void wangzqh()
{
	cin >> n >> d;
	for (int i = 1;i <= n;i++) cin >> X[i];
	for (int i = 1;i <= n;i++)
	{
		L[i] = lower_bound(X + 1, X + n + 1, X[i] - d) - X;
		R[i] = upper_bound(X + 1, X + n + 1, X[i] + d) - X - 1;
	}
	for (int i = 1;i <= n;i++)
	{
		int pos1 = lower_bound(L + i + 1, L + R[i] + 1, i) - L;
		int pos2 = lower_bound(L + i + 1, L + R[i] + 1, i - 1) - L;
		A[i] = R[i] - pos1 + 1; B[i] = pos1 - pos2;
	}
	for (int i = n;i >= 1;i--)
	{
		FA[i] = FB[i] = GA[i] = GB[i] = HA[i] = HB[i] = 0;
		if (R[i] == i) continue;
		if (R[R[i]] == R[i]) continue;
		FA[i] = A[R[i]]; FB[i] = B[R[i]];
		int t = R[R[i]];
		if (L[t] <= R[i] - 2) continue;
		if (L[t] == R[i] - 1)
		{
			HA[i] += FA[R[i]] + GA[R[i]]; 
			HB[i] += FB[R[i]] + GB[R[i]];
			continue; 
		}
		if (L[t - 1] == R[i])
		{
			FA[i] += FA[R[i]]; FB[i] += FB[R[i]];
			GA[i] += GA[R[i]]; GB[i] += GB[R[i]];
			HA[i] += HA[R[i]]; HB[i] += HB[R[i]];
			continue;
		}
		FA[i] += FA[R[i]] - A[t]; FB[i] += FB[R[i]] - B[t];
		GA[i] += GA[R[i]] + A[t]; GB[i] += GB[R[i]] + B[t];
		if ((R[t] > t) && (L[R[t]] == t)) HA[i] += HA[R[i]], HB[i] += HB[R[i]];
	}
	ll ans = 0;
	for (int i = 1;i <= n;i++) ans += FB[i] + HA[i];
	cout << ans << "\n";
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	init();
	cin >> byx >> aqx;
	while (aqx--) wangzqh();
	return 0;
}
