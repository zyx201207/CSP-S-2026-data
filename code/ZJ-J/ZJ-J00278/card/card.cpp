#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=5e5+10;
constexpr int maxm=3e5+10;

int n,m;
int a[maxn];
int tag[maxn];
int add[maxm];

int to[maxn];
int ans[maxm];
int lst[maxm];

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        tag[i]=1;
    }

    for(int i=n;i>=1;--i)
    {
        if(lst[a[i]])
        {
            to[i]=lst[a[i]];
        }
        else
        {
            to[i]=i+1;
            add[i]=a[i];
        }
        lst[a[i]]=i;
    }

    for(int i=1;i<=n;++i)
    {
        ans[add[i]]+=tag[i];
        tag[to[i]]+=tag[i];
    }

    for(int i=1;i<=m;++i)
    {
        printf("%lld ",ans[i]);
    }
    printf("\n");
    return 0;
}