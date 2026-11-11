#include<bits/stdc++.h>
using namespace std;
int T, n, a[200005], x;
long long ans;
char c, b[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> c;
        a[++x] = n;
        b[x] = c;
    }
    int l = 1, r = x;
    while(l < r)
    {
        if(b[l] == b[r])
        {
            if(a[l] == a[r])
                l++, r--;
            if(a[l] < a[r])
            {
                a[r] -= a[l];
                l++;
            }
            if(a[l] > a[r])
            {
                r--;
                a[l] -= a[r];
            }
        }
        else
        {
            ans += min(a[l], a[r]);
            if(a[l] == a[r])
                l++, r--;
            if(a[l] < a[r])
            {
                a[r] -= a[l];
                l++;
            }
            if(a[l] > a[r])
            {
                a[l] -= a[r];
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
