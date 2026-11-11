#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

using lnt = long long;

const int MAXN = 1e5+10;
const int MAXK = 3e3+10;

int a[MAXN], t[MAXN][MAXK], cnt[MAXK], ans[MAXK], lst[MAXK];

void Solve()
{
	int n,k; cin >> n >> k;
	if (n <= (int)2e5 && k <= 3000)
	{
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
			for (int j=1;j<=k;j++) t[i][j] = t[i-1][j] + (a[i] == j); 
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				if (lst[a[j]])
				{
					for (int l=1;l<=k;l++) cnt[l] -= t[j-1][l]-t[lst[a[j]]-1][l];
				}
				lst[a[j]] = j; cnt[a[j]]++;
			}
			for (int j=1;j<=k;j++) ans[j] += (cnt[j] != 0);
			for (int j=1;j<=k;j++) lst[j] = 0, cnt[j] = 0;
		}
		for (int i=1;i<=k;i++) cout << ans[i] << " ";
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
