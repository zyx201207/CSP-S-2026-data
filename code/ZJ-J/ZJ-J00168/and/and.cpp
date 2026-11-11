#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n,m;
int a[maxn];
int ans;
vector<int> v;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    v.clear();
    for(int i=30;i>=0;--i)
    {
        if(v.empty())
        {
            int cnt=0;
            for(int j=1;j<=n;++j)
            {
                if((a[j]>>i)&1)
                {
                    ++cnt;
                    v.emplace_back(j);
                }
            }
            if(cnt>=m)
            {
                ans<<=1;
                ans|=1;
            }
            else
            {
                ans<<=1;
                v.clear();
            }
        }
        else
        {
            int cnt=0;
            vector<int> tmp;
            for(int vi:v)
            {
                if((a[vi]>>i)&1)
                {
                    ++cnt;
                    tmp.emplace_back(vi);
                }
            }
            if(cnt>=m)
            {
                ans<<=1;
                ans|=1;
                v=tmp;
            }
            else
            {
                ans<<=1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
