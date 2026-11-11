#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005]={};
    char c[200005]={};
    cin >> n;
    string s,sa[200005]={};
    long long l=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        for (int j=1;j<=a[i];j++)
        {
            s = s+c[i];
        }
        l += a[i];
    }
    /*long long ss=0;
    for (int i=1;i<=n;i++)
    {
        s[ss] = c[i];
        s[l-ss-1] = c[n-i+1];
        ss += min(a[i],a[n-i+1]);
    }*/
    long long lc=1,rc=n,sum=0,cnt=0;
    for (long long i=0;i<l/2;)
    {
        if (s[i]!=s[l-i-1])
        {
            //cnt++;
            cnt += min(a[lc],a[rc]);
        }
        i += min(a[lc],a[rc]);
        sum += min(a[lc],a[rc]);
        if (sum>=max(a[lc],a[rc]))
        {
            sum = 0;
            lc += (a[lc]>=a[rc]);
            rc += (a[rc]>=a[lc]);
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
