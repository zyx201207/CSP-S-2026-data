#include <bits/stdc++.h>
using namespace std;
long long c,T,n,k,ans,cnt=0,res,a[2000010];
void dfs(long long u,long long t,long long num)
    {
        if(u>t)return;
        if(cnt>2)return;
        if(u==t)
            {
                if(ans==num)cnt++;
                if(ans>num)ans=min(ans,num),cnt=1;
                if(cnt>2)return;
                return ;
            }
        if(num>ans)return;
        for(int i=t;i>=u+1;i--)
            {
                if(a[i]-a[u]>k)continue;
                dfs(i,t,num+1);
                if(cnt>2)return;
            }
        return;
    }
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    if(c==11||c==12)
        {
            while(T--)
                {
                    scanf("%lld%lld",&n,&k);
                    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
                    long long cha=a[2]-a[1],sh=k/cha;
                    if(sh!=0&&sh!=1)printf("%lld\n",max(0ll,n-sh*2+1));
                        else printf("0\n");
                }
            return 0;
        }
    while(T--)
        {
            scanf("%lld%lld",&n,&k),res=0;
            for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    {

                        ans=20000000,cnt=0;
                        dfs(i,j,0ll);
                        if(cnt==2)res++;
                    }
            printf("%lld\n",res);
        }
    return 0;
}
