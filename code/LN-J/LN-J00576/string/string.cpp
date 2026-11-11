#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        cin>>c[i];
    }
    int frt=1,lt=n,cnt=0;
    while(frt<lt)
    {
        if(a[frt]>a[lt])
        {
            if(c[frt]!=c[lt]) cnt=cnt+a[lt];
            a[frt]-=a[lt];
            lt--;
        }
        else if(a[frt]<a[lt])
        {
            if(c[frt]!=c[lt]) cnt=cnt+a[frt];
            a[lt]-=a[frt];
            frt++;
        }
        else
        {
            cnt+=a[frt];
            frt++;
            lt--;
        }
    }
    printf("%lld",cnt);
    return 0;
}
