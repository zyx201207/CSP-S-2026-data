#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n,m;
int a[maxn];
int nxt[maxn];
int pre[maxn];
int las[maxn];
int cnt[maxn];
bool appeared[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i-1;j<=n;++j)
        {
            nxt[j]=pre[j]=n+1;
            appeared[j]=las[j]=0;
        }
        for(int j=i;j<=n;++j)
        {
            if(!las[a[j]])
            {
                nxt[j-1]=j;
                pre[j]=j-1;
            }
            else
            {
                int &lst=las[a[j]];
                int &k=pre[lst];
                nxt[k]=j;
                pre[j]=k;
                nxt[lst]=pre[lst]=n+1;
            }
            las[a[j]]=j;
        }
        nxt[n]=pre[0]=n+1;
        int now=i-1;
        while(now<=n)
        {
            appeared[now]=1;
            now=nxt[now];
        }
        for(int j=1;j<=m;++j)
        {
            if(appeared[j])
            {
                ++cnt[j];
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        printf("%lld ",cnt[i]);
    }
    return 0;
}

