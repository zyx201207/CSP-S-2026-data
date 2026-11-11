#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    long long qwe,asd;
    int flag;
    for(int i=n;i>=1;i--)
    {
        qwe=0;
        asd=1;
        flag=0;
        for(int j=i-1;j>=1;j--)
        {
            qwe+=a[i]-a[j];
            asd++;
            if(qwe>m)
            {
                //cout<<1<<' '<<i<<' '<<j<<' '<<ans<<' '<<asd-1<<endl;
                ans=max(ans,asd-1);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            ans=max(ans,asd);
            //cout<<2<<' '<<i<<' '<<ans<<' '<<asd<<endl;
            printf("%lld",ans);
            return 0;
        }
    }
    printf("%lld",ans);
    return 0;
}
