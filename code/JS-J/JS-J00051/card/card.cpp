#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, num[N];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (num[i] != num[i + 1])
        {
            cout << num[i] << " ";
        }
    }
    return 0;
}
