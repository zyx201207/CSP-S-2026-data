#include<bits/stdc++.h>
using namespace std;
long long a[2200000];
int nxt[2200000];
int main()
{
    int c,T,n;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    long long d;
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%lld",&d);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[n]-a[i]<=d)
            {
                nxt[i]=n;
                continue;
            }
            auto it=upper_bound(a+1,a+n+1,a[i]+d);
            nxt[i]=(it-a-1);
        }
        int l1,r1;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=i;
            int y=nxt[x];
            if(x==y)continue;
            l1=i+1,r1=y;
            x=y,y=nxt[x];
            while(true)
            {
                if(x==y)break;
                int nl1,nr1;
                nl1=nxt[r1-1]+1;
                nr1=y;
                if(nl1>nr1)
                {
                    if(r1-l1+1>=2)
                    {
                        if(y>=nxt[r1-2]+1)
                        {
                            ans+=(y-nxt[r1-2]);
                            int tmp=y;
                            while(nxt[tmp]>nxt[tmp-1])
                            {
                                ans++;
                                tmp=nxt[tmp];
                            }
                        }
                    }
                    break;
                }
                if(r1-l1+1>=2)
                {
                    if(nl1-1>=nxt[r1-2]+1)ans+=(nl1-nxt[r1-2]-1);
                }
                if(y==n)break;
                l1=nl1,r1=nr1;
                x=y,y=nxt[x];
            }
        }
        printf("%lld\n",ans);
    }
}
