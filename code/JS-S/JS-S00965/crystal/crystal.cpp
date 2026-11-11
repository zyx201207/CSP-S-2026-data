#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int Maxn = 5e5 + 5;

ll n, m;
ll a[Maxn], b[Maxn];

inline void read(ll &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while(!isdigit(ch)) f = ch == '-' ? -1 : f, ch = getchar();
    while( isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    sort(a + 1, a + 1 + n);
    int Max = 0;
    for (int i = 1; i <= n; ++i)
    {
        b[i] = b[i - 1] + a[i];
        int l = 1, r = i;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if((i - mid + 1) * a[i] - m <= b[i] - b[mid - 1]) r = mid;
            else l = mid + 1;
        }
        Max = max(Max, i - l + 1);
    }
    cout << Max <<endl;
    return 0;
}
