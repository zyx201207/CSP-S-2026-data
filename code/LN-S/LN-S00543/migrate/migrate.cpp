#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5003;
int c,t;
int n,d;
int x[N];
int dis[N][N];
int cnt[N][N];
int ans;
void specialA()
{
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
    }
    if(2*(x[2]-x[1])<=d and 3*(x[2]-x[1])>d)
    {
        printf("%lld\n",max(0ll,n-3ll));
    }
    else
    {
        puts("0");
    }
}
void solve()
{
    ans=0;
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(x[j]-d>x[i]) break;
            dis[i][j]=1;
            //printf("%lld can %lld\n",i,j);
        }
    }
    for(int mid=1;mid<=n;mid++)
    {
        for(int l=1;l<mid;l++)
        {
            for(int r=mid+1;r<=n;r++)
            {
                if(dis[l][r] == dis[l][mid]+dis[mid][r])
                {
                    if(cnt[l][r]==1) 
                    {
                        //printf("discnt %lld %lld\n",l,r);
                        ans--;
                    }
                    if(cnt[l][r]==0) 
                    {
                        //printf("cnt %lld %lld\n",l,r);
                        ans++;
                    }
                    cnt[l][r]++;
                }
                if(dis[l][r] > dis[l][mid]+dis[mid][r])
                {
                    if(cnt[l][r]==1)
                    {
                        //printf("del and ");
                        ans--;
                        cnt[l][r]=0;
                    }
                    //printf("refresh %lld %lld by %lld\n",l,r,mid);
                    dis[l][r]=dis[l][mid]+dis[mid][r];
                }
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         printf("%lld ",dis[i][j]);
    //     }
    //     puts("");
    // }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c==11 or c==12)
    {
        while(t--)
        {
            specialA();
        }
        return 0;
    }
    while(t--)
    {
        solve();
    }
    return 0;
}
