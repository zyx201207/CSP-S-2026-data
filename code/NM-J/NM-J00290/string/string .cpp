#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;cin >> n;
    long long a[n],newa[n];
    string c[n],newc[n];
    for(int b=1;b<=n;b++)
    {
        cin >> a[b] >> c[n];
            if(b<=n/2)
            {
                newa[b]=a[b];
                newc[b]=c[b];
            }
    }
    for(int b=n/2;b>=1;b--)
    {
        for(int c=n;c>=n/2;c--)
        {
            if(newc[b]!=newc[c])
            ans=ans+newa[b];
        }
    }cout << ans;
}
