#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans = 0,k = 1,l;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    l = n;
    while(true)
    {
        if(k == l || k - l == 1)
        {
            cout << ans;
            return 0;
        }
        else if(c[k] == c[l])
        {
            if(a[k] > a[l])
            {
                a[k] -= a[l];
                l--;
            }
            else if(a[k] < a[l])
            {
                a[l] -= a[k];
                k++;
            }
            else
            {
                l--;
                k++;
            }
        }
        else
        {
            if(a[k] > a[l])
            {
                a[k] -= a[l];
                ans += a[l];
                l--;
            }
            else if(a[k] < a[l])
            {
                a[l] -= a[k];
                ans += a[k];
                k++;
            }
            else
            {
                ans += a[k];
                k++;
                l--;
            }
        }
    }
    return 0;
}
