#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ll long long
using namespace std;

const int MAXN = 5e5 + 5;

ll n, m;
ll a[MAXN];
ll b[MAXN];

int main(){
    //freopen("crystal3.in", "r", stdin);
    //freopen("crystal.out", "w", stdout);
    buff;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[j] >= 0)
            {
                b[i] += a[j];
            }
            else
            {
                b[i] -= a[j];
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (b[i] <= m)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
