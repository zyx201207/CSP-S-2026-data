#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005], n, m, ans[200005];
int main()
{
    freopen("cards.in", "r", stdin);
    freopen("cards.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ll head = i;
        while(head <= n)
        {
            ll pos = head + 1;
            for (int j = n; j > head; j--)
            {
                if (a[j] == a[head])
                {
                    pos = j + 1;
                    break;
                }

            }
            ans[a[head]]++;
            //cout << a[head] << ' ';
            head = pos;
        }
        //cout << endl;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
// 10 3 3 1 2 1 3 2 3 1 2 1
