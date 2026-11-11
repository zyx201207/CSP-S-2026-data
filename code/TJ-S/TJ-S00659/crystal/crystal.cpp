#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // "\n"
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	long long ans = 0;
	long long cha = 0;
	for (int i = 1, j = 1; i <= j && j <= n; j++)
	{
		cha += (a[j] - a[j - 1]) * (j - i); 
		while (cha > m && i <= j)
		{
			cha -= a[j] - a[i];
			i++;
		}
//		cout << i << " " << j << " " << cha << "\n";
		ans = max(ans, (j - i + 1) * 1ll); 
	}
	cout << ans << endl;
    return 0;
}

//´Ë¾Ù±ØÊ¤!!!
//AKCSP!!! 
