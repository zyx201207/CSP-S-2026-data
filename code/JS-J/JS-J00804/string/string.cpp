#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<char> c(n);
    ll cnt=0;
    for (int i=0;i<n;i++)
    {
        cin >> a[i] >> c[i];
        cnt+=a[i];
    }
    if (n==1)
    {
        cout << 0;
        return 0;
    }
    ll ans=0,mid=cnt/2;
    ll idl=0,idr=n-1;
    ll l=0,r=n-1,t=0,ok=0;
    while (idl<idr&&l<r&&l<mid&&r>mid)
    {
        t=min(a[idl],a[idr]);
        l+=t,r-=t;
        if (c[idl]!=c[idr])
        {
            ans+=t;
        }
        if (a[idl]<a[idr])
        {
            idl++;
            a[idr]-=a[idl];
        }
        else if (a[idr]>a[idl])
        {
            idr--;
            a[idl]-=a[idr];
        }
        else
        {
            idl++,idr--;
        }
        ok+=t*2;
    }
    if (ok!=cnt)
    {
        if (ok>cnt)
        {
            ok-=t*2;
            l-=t,r-=t;
        }
        if (ok<cnt)
        {
            while (l<r)
            {
                l++,r--;
                if (c[idl]!=c[idr])
                {
                    ans++;
                }
                if (a[idl]<a[idr])
                {
                    idl++;
                    a[idr]-=a[idl];
                }
                else if (a[idr]>a[idl])
                {
                    idr--;
                    a[idl]-=a[idr];
                }
                else
                {
                    idl++,idr--;
                }
                ok+=2;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}