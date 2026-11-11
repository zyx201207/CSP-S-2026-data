#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=2e5+13;

int n,m;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    ll ans=0;
    for(int _=30;_>=0;--_)
    {
        ll base=1ll<<_;
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]>>_&1)
            {
                ++cnt;
            }
        }
        if(cnt>=m)
        {
            vector<int>b;
            b.reserve(cnt);
            for(int i=0;i<n;++i)
            {
                if(a[i]>>_&1)
                {
                    b.push_back(a[i]);
                }
            }
            ans|=base;
            n=cnt;
            a=b;
        }
    }
    printf("%lld\n",ans);

    return 0;
}

