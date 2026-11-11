//wangyichitongchuanshidierzhongxueSN-J00668
#include <bits/stdc++.h> 
using namespace std;
const int N = 500005;

int n, m, a[N], cnt[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			for (int k = j; k <= n; k++)
				if (a[j] == a[k]) j = k;
			cnt[a[j]]++;
		}
	for (int i = 1; i <= m; i++) 
		cout << cnt[i] << " ";
	return 0;
}

