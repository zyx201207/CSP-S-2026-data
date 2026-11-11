#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,n;
struct node
{
    ll len;
    char c;
} a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i = 1; i <= n; i ++)
    {
        cin>>a[i].len>>a[i].c;
    }
    ll l = 1, r = n;
    while(l<r)
    {
        if(a[l].len>a[r].len)
        {
            a[l].len -= a[r].len;
            if(a[l].c != a[r].c)ans+=a[r].len;
            r--;
        }
        else if (a[l].len<a[r].len)
        {
            a[r].len -= a[l].len;
            if(a[l].c != a[r].c)ans+=a[l].len;
            l++;
        }
        else
        {
            if(a[l].c != a[r].c)ans+=a[l].len;
            l++,r--;
        }
    }
    cout << ans<<'\n';
    return 0;
}
