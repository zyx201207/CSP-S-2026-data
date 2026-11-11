#include<bits/stdc++.h>
using namespace std;
const int p = 200005;

int n, m, a[p];
bool f[p];

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
		cin >> a[i];
    for(int i=29; i>=0; i--)
    {
		int cnt = 0;
		for(int j=1; j<=n; j++)
		{
			f[j] = (a[j]>>i)%2;
			if(f[j]) cnt++;
		}
		if(cnt >= m)
		{
			int k = n;
			for(int i=1; i<=k; i++)
				if(!f[i])
				{
					swap(a[i], a[k]);
					f[i] = f[k];
					k--; i--;
				}
			n = k;
			if(n == m) break;
		}
    }
    int ans = a[1];
    for(int i=2; i<=m; i++)
		ans = ans&a[i];
	cout << ans;
    return 0;
}
