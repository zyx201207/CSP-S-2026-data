#include<bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define inf (LLONG_MAX>>1)

constexpr int maxn=2e5+10;

int n,m;
int a[maxn];
vector<int> id[40];
bool is[maxn];
bool tmp[maxn];
int ans=0;

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        is[i]=1;
    }
    for(int j=39;j>=0;--j)
    {
        for(int i=1;i<=n;++i)
        {
            if((a[i]>>j)&1)
            {
                id[j].emplace_back(i);
            }
        }
    }

    for(int j=39;j>=0;--j)
    {
        int cnt=0;
        for(int i=1;i<=n;++i) tmp[i]=0;

        for(int i:id[j])
        {
            if(is[i]) ++cnt;
            tmp[i]=1;
        }

        if(cnt>=m)
        {
            ans|=(1ll<<j);
            for(int i=1;i<=n;++i)
            {
                is[i]&=tmp[i];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}