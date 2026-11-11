#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l=1,r,temp;
long long a[200005];
char c[200005];


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    r = n;
    while(l<r)
    {
        temp = min(a[l],a[r]);
        if(c[l]==c[r])
        {
            a[l]-=temp;
            a[r]-=temp;
        }
        else{
            ans+=temp;
            a[l]-=temp;
            a[r]-=temp;
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    printf("%lld",ans);
    return 0;
}
