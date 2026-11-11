#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],an;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out"."w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int lp=1,rp=n,l=a[1],r=a[n];
    char lc=c[1],rc=c[n];
    while(lp<=rp)
    {
        if (l>r)
        {
            if (lc!=rc)
            {
                an+=r;
            }
            l-=r;
            rp--;
            r=a[rp];
            rc=c[rp];
        }
        else if (l<r)
        {
            if (lc!=rc)
            {
                an+=l;
            }
            r-=l;
            lp++;
            l=a[lp];
            lc=c[lp];
        }
        else
        {
            if (lc!=rc)
            {
                an+=l;
            }
            lp++;
            rp--;
            l=a[lp];
            r=a[rp];
            lc=c[lp];
            rc=c[rp];
        }
    }
    cout<<an;
    return 0;
}
