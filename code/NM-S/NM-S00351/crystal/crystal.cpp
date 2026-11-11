#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ptsm[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
    	ptsm[i] = ptsm[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    	if (ptsm[i] == m)
    	{
    		for (int j = i + 1; ; j++)
    		{
    			if (a[j] != a[i])
    			{
    				cout << j - 1 << endl;
    				return 0;
				}
			}
		}
		if (ptsm[i] > m)
    	{
    		i--;
    		for (int j = i + 1; ; j++)
    		{
    			if (a[j] != a[i])
    			{
    				cout << j - 1 << endl;
    				return 0;
				}
			}
		}
	} 
	return 0;
}

