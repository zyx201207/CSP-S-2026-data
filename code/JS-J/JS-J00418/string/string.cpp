#include <bits/stdc++.h>
using namespace std;
int a[200005],n;
char b[200005];
long long ans;
void dg(int l,int r)
{
    if (l >= r || a[l] == 0 || a[r] == 0) return ;
    if (b[l] != b[r])
    {
        if (a[l] > a[r])
        {
            ans += a[r];
            a[l] -= a[r];
            a[r] = 0;
            dg(l,r-1);
        }
        else if (a[l] < a[r])
        {
            ans += a[l];
            a[r] -= a[l];
            a[l] = 0;
            dg(l+1,r);
        }
        else{
            ans += a[l];
            a[l] = 0;
            a[r] = 0;
            dg(l+1,r-1);
        }
    }
    else
    {
        if (a[l] > a[r])
        {
            a[l] -= a[r];
            a[r] = 0;
            dg(l,r-1);
        }
        else if (a[l] < a[r])
        {
            a[r] -= a[l];
            a[l] = 0;
            dg(l+1,r);
        }
        else{
            a[l] = 0;
            a[r] = 0;
            dg(l+1,r-1);
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    dg(1,n);
    cout << ans;
    return 0;
}
