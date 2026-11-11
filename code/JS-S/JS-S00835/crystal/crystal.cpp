#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
ll n, m, a[N], d[N], s[N];
ll max_len = INT_MIN;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    // for (int i = 1; i<= n; i ++)
    // {
    //     cerr << a[i] << " ";
    // }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i ++)
    {
        d[i] = a[i] - a[i - 1];
        s[i] = abs(s[i - 1] + d[i]);
    }
    for (int i = 1; i<= n; i ++)
    {
        // cerr << "chafen: " << d[i] <<  " qzh" << s[i] << endl;
    }
    ll head = 1, tail = 1;
    while (tail <= n)
    {
        ll energy_need = 0;
        while (energy_need <= m && tail <= n)
        {
            tail ++;
            energy_need += s[tail - 1];
            // cerr << tail << ' ' << energy_need << endl;
        }
        energy_need -= s[tail - 1];
        // cerr << energy_need << " ";
        // cerr << tail << " " << head << endl;
        max_len = max(max_len, tail - head - 1);
        head ++;
    }
    cout << max_len << endl;
    return 0;
}