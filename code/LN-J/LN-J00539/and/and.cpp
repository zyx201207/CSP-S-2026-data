#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
vector<int> able_bit;
int bit[31];

bool cmp(int a, int b)
{
    for(int i : able_bit)
    {
        if((a & (1 << i)) != (b & (1 << i)))
            return (a & (1 << i)) > (b & (1 << i));
    }
    return 0;
}

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int k = 1; k <= n; k++)
    {
        cin >> a[k];
        int x = a[k], i = 0;
        while(x)
        {
            if(x & 1) bit[i]++;
            x >>= 1; i++;
        }
    }

    for(int i = 30; i >= 0; i--)
        if(bit[i] >= m) able_bit.push_back(i);

    sort(a + 1, a + n + 1, cmp);

    int ans = a[1];

    for(int i = 2; i <= m; i++)
        ans &= a[i];
    cout << ans << "\n";

    /*

    cout << "able_bit : ";
    for(int x : able_bit) cout << x << " ";
    cout << "\n";

    cout << "a : ";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";

    */


    return 0;
}
