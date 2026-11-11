#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, l = 2, r = 2;
    long long m, maxn = 1;
    cin >> n >> m;
    const int N = n + 5;
    long long a[N], b[N];
    b[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
    	b[i] = a[i] - a[i - 1];
    }
    while (r <= n)
    {
    	long long s = 1, z = 0;
    	for (int i = l; i <= r; i++)
    	{
    		z += b[i] * (i - 1);
    		if (z <= m)
   		 	{
    			r++; s++;
			}
			else
			{
				maxn = max(maxn, s);
				z = 0; s = 1;
				break;
			}
		}
		l++;
		r = l + 1;
	}
    if (maxn == 1) cout << 0;
    else cout << maxn;
    return 0;
}
