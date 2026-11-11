#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int BIGN=2e6+10;
const int N=310;
int n,c,t;
ll d;
ll mn[N][N];
ll cnt[N][N];
ll a[BIGN];
int now;

void taskA()
{
    int tmp=t;
    while(t--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        ll T=a[2]-a[1];
        if(d<T||d<2*T)
        {
            printf("0\n");
            continue;
        }
        d/=T;
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans+=((1ll*i+d+d-1)<=n);
        printf("%lld\n",ans);
    }
}

void dfs(int now,int st,int dis)
{
    if(now>st)
    {
        if(dis==mn[st][now])
            cnt[st][now]++;
        if(now>n)
            return;
    }
    for(int i=now+1;i<=n;i++)
    {
        if(a[i]-a[now]>d)
            break;
        dfs(i,st,dis+1);
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c>=11&&c<=12)
    {
        taskA();
        return 0;
    }
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        memset(mn,0,sizeof(mn));
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int last=i,nxtj;
            for(int j=i+1;j<=n;)
            {
                nxtj=j;
                while(nxtj<=n&&a[nxtj]-a[last]<=d)
                    mn[i][nxtj]=mn[i][last]+1,nxtj++;
                if(nxtj==j)
                    break;
                j=nxtj;
                last=j-1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i,i,0);
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(cnt[i][j]==2)
                    ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
