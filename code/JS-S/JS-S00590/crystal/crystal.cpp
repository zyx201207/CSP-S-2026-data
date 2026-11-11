#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0,cnt;
const int N=5*1e5+1000;
const int M=1e12;
int a[N];
int i,j;
bool chck2()
{
    if(cnt<=m)
    {
       return 1;
    }
    else  return 0;
}
signed main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int ii=0,jj=0;
    a[0]=a[1];
    i=1,j=1,cnt=0;
    while(j<=n&&i<=n)
    {
        while(chck2()==1)
        {
            if(j-i+1>ans)
            {
               ans=j-i+1;
            }
            j++;
            cnt+=(a[j]-a[j-1])*(j-i);
            if(j>n)  break;
        }
        while(chck2()==0)
        {
            cnt-=a[j]-a[i];
            i++;

        }
    }
    printf("%lld",ans);
}
//51965
