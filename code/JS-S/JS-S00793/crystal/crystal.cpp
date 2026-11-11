#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],res=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long ne=0;
    long long j=1;
    long long i=1;
    for(;i<n;i++)
    {
        if(ne<=m)
        {
            res=max(res,j-i+1);
        }
        ne-=(a[j]-a[i]);
        //cout<<ne<<' '<<i<<endl;
        if(ne>m)continue;
        for(;j<n;)
        {
            j++;
            ne+=(j-i)*(a[j]-a[j-1]);
            //cout<<ne<<' '<<j<<endl;
            while(a[j]==a[j+1])j++;
            if(ne<=m)
            {
                res=max(res,j-i+1);
            }
            if(ne>m)
            {
                i--;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}
