#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int maxn = 2e5+10;

int wi[maxn];
vector<int> idx[40];
int vis[maxn];

inline void prt2(const int& n)
{
    for(int i=8;~i;--i)
    {
        putchar('0' + ((n&(1<<i))>0) );
    }
    putchar('\n');
}

inline void add(const int &n,const int &id)
{
    for(int i=30;~i;--i)
    {
        if(n&(1<<i))
        {
            idx[i].emplace_back(id);
        }
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&wi[i]);
        add(wi[i],i);
        vis[i]=1<<30;
    }
    int lst=30;
    int ans=0,cnt=0;
    for(int i=29;~i;--i)
    {
        if(lst==30 && (int)idx[i].size()==m)
        {
            ans=wi[idx[i][0]];
            for(const int &id : idx[i])
            {
                ans&=wi[id];
            }
            break;
        }

        cnt=0;
        if((int)idx[i].size()>=m)
        {
            for(const int &id : idx[i])
            {
                if(lst==30 || (vis[id]&ans)==ans) ++cnt;
                vis[id] |= 1<<i;
            }
            if(cnt>=m)
            {
                ans|=1<<i;
                lst=i;
            }
        }
    }
    printf("%lld\n",ans);

    return 0;
}
















