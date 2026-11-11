#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005][2]={},ans=0,l,r,lpos,rpos;
ll x,on;
char c[200005]={};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x;
        a[i][0] = a[i-1][1]+1;
        a[i][1] = a[i][0]+x-1;
        cin >> c[i];
    }
    l = 1;
    lpos = 1;
    r = a[n][1];
    rpos = n;
    while (l < r)
    {
        if (c[lpos] != c[rpos])
        {
            on = min(r-a[rpos][0]+1,a[lpos][1]-l+1);
            ans += on;
            l = l+on-1;
            r = r-on+1;
        }
        l++;
        r--;
        if (l > a[lpos][1]) lpos++;
        if (r < a[rpos][0]) rpos--;
    }
    cout << ans;
    return 0;
}
