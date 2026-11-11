#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,num,sum,ans,s;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    l=r=num=1;
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,num);
        s=(a[i]-a[i-1])*num;
        if(s+sum<=m)
        {
            sum+=s;
            num++;
            r++;
        }
        else
        {
            while(l<r)
            {
                sum-=(a[r]-a[l]);
                l++;
                num--;
                s=(a[i]-a[i-1])*num;
                if(sum+s<=m)
                {
                    sum+=s;
                    num++;
                    r++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
