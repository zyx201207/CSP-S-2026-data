#include <bits/stdc++.h>
#define Int long long
using namespace std;

const int N = 2e6 + 10;

int n;
Int a[N], b[N];

void solve()
{
	int k; cin >> n >> k;
	if (k == 1) 
	{
		cout << 0 << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	b[0] = 1e9 + 7;
	for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
	n--;
	Int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int lst = 0, st = i, flag = 0;
		for (int j = i; j <= n; j++)
		{
			if (b[j] > k) break;
			if (lst + b[j] > k)
			{
				if (st > i && lst + b[j - 1] <= k && (lst + b[j - 1] + b[j - 2] > k || j - 2 < i)) flag = 1;
				lst = lst + b[j] - k;
				st = j;
			}
			else lst += b[j];
			if (flag) ans++;
		}
		if (st > i && lst + b[j - 1] <= k && (lst + b[j - 1] + b[j - 2] > k || j - 2 < i) && !flag) ans++;
	}
	cout << ans << '\n';
	return;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, T = 1; cin >> c >> T;
	while (T--) solve();
	return 0;
}

//The Final One!!! But I can't manage it?...Crazy...

//Except:?+?+?+? ???

//WuLiHuiTian.jpg
// I HATE *********!!!

//WoCaiJinNianShiKenDingBuHuiYouRenJiangWoSongShangZJMiHuoXingWeiDaShangDe

//ZheXieWenZiXianRanBuHuiBeiZhuYiDaoBa...Maybe...

//Failed...KongBeiQie...GG /114
