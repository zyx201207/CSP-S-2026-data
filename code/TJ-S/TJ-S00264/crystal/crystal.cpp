#include <bits/stdc++.h> //Howson
using namespace std;

int n, cnt;
long long m, num, a[500005];
bool f = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) if (a[i] != a[1]) f = false;
    if (f)
    {
        cout << n;
        return 0;
    }

    sort(a + 1, a + n + 1);
    if (n % 2 != 0) num = a[n / 2 + 1];
    else num = a[n / 2];
    int k = 0;

    for (int i = n / 2; i >= 1 && m >= 1; i--)
    {
    	m = (m - num + a[i]);
        a[i] = a[i] + (num - a[i]);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == num)
        {
            cnt++;
            k = i;
        }
    if (m)
    {
        for (int i = k + 1; i <= n; i++)
        {
            int chcnt = 0;
            for (int j = k; j >= 1 && m; j--)
            {
            	m = m - (a[i] - a[j]);
                a[j] = a[j] + (a[i] - a[j]);
            }

            for (int j = 1; j <= n; j++) if (a[i] == a[j]) chcnt++;
            if (chcnt < cnt) break;
            else cnt = chcnt;
        }
    }

    cout << cnt;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
