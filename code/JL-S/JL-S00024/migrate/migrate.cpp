#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,ans,d,a[2000005];
void dfs(long long u,int step,long long lim,long long ed,long long b,long long &c)
{
    if(step>=lim+1)
    {
        if(u==ed)c++;
        return ;
    }
    if(u+(lim-step+1)*b<ed)return ;
    for(long long i=u+1;i<=upper_bound(a+1,a+n+1,a[u]+b)-a-1;i++)dfs(i,step+1,lim,ed,b,c);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--)
    {
        ans=0;
        scanf("%lld %lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(a[1]+d>=a[n])
        {
            printf("0\n");
            continue;
        }
        long long pl=upper_bound(a+1,a+n+1,a[1]+d)-a-1;
        long long pr=lower_bound(a+1,a+n+1,a[n]-d)-a;
        if(pl>=pr)
        {
            long long wnd=pl-pr+1;
            if(wnd>2)
            {
                printf("0\n");
                continue;
            }
            for(int i=1;i<pr;i++)
            {
                long long p1=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
                if(p1-pr>1)break;
                else if(p1==pl)p1=pr-1;
                if(wnd==2)
                {
                    long long p2=upper_bound(a+1,a+n+1,a[p1]+d)-a;
                    ans+=(n-p2+1);
                }
                else
                {
                    if(p1>pl)
                    {
                        long long p2=upper_bound(a+1,a+n+1,a[pr-1]+d)-a;
                        ans+=n-p2+1;
                    }
                    else
                    {
                        long long p2=upper_bound(a+1,a+n+1,a[p1]+d)-a-1;
                        long long p3=upper_bound(a+1,a+n+1,a[p1-1]+d)-a;
                        p3=max(p3,pl+1);
                        if(p2<p3)continue;
                        ans+=p2-p3+1;
                    }
                }
            }
            printf("%lld\n",ans);
            continue;
        }
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]<=d)continue;
                long long mn=0;
                long long pii=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
                pii=upper_bound(a+1,a+n+1,a[pii]+d)-a-1;
                if(pii>=j)mn=2;
                for(long long len=3;(len<=j-i)&&mn==0;len++)
                {
                    pii=upper_bound(a+1,a+n+1,a[pii]+d)-a-1;
                    if(pii>=j)
                    {
                        mn=len;
                        break;
                    }
                }
                long long cnt=0;
                dfs(i,1,mn,j,d,cnt);
                if(cnt==2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
