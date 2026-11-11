#include<bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i] >> c[i];
    }
    long long idl = 1,idr = n,remainl = a[1],remainr = a[n];
    long long ans = 0;
    while(idr>idl)
    {
        long long sum = min(remainl,remainr);
        if(c[idl]!=c[idr])
        {
            ans+=sum;
        }
        if(sum==remainl)
        {
            remainl = a[++idl];
        }
        else
        {
            remainl-=sum;
        }
        if(sum==remainr)
        {
            remainr = a[--idr];
        }
        else
        {
            remainr-=sum;
        }
    }
    cout << ans;
    return 0;
}
