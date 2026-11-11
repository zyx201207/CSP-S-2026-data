#include <bits/stdc++.h>
#define int long long
using namespace std;

static char puf[1<<20];
static signed len=0,pos=0;
inline signed gc(){
    if(len==pos)
    {
        len=(int)fread(puf,1,sizeof puf,stdin);
        pos=0;
        if(len==0) return EOF;
    }
    return puf[pos++];
}
template <typename T>
inline void read(T &x){
    x=0;
    signed f=1,c=gc();
    while(!isdigit(c))
    {
        if(c=='-') f=-1;
        c=gc();
    }
    while(isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=gc();
    }
    x*=f;
}

constexpr int maxn = 2e6+10;
constexpr int maxm = 2e6+10;

int di[maxn];

inline void solve()
{
    int n,d;
    read(n),read(d);
    for(int i=1;i<=n;++i)
    {
        read(di[i]);
    }
    int tal=di[1]+d;
    queue<int> lst;
    int j=1;
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        if(di[i]<=tal)
        {
            if(lst.size()<3) lst.emplace(i);
            else
            {
                lst.pop();
                lst.emplace(i);
            }
        }
        while(di[i]>tal)
        {
            if(lst.size()==2)
            {
                int lst2=lst.front(); lst.pop();
                int lst1=lst.front(); lst.pop();
                int l=upper_bound(di+lst1-1,di+1+n,di[lst1])-di;
                int r=upper_bound(di+lst1-1,di+1+n,di[lst2]+d)-di-1;
                if(r>=l) ans+=r-l+1;
                lst.emplace(lst2);
                lst.emplace(lst1);
            }
            else if(lst.size()==3)
            {
                int lst3=lst.front(); lst.pop();
                int lst2=lst.front(); lst.pop();
                int lst1=lst.front(); lst.pop();
                int l=upper_bound(di+lst1-1,di+1+n,di[lst3]+d)-di;
                int r=upper_bound(di+lst1-1,di+1+n,di[lst2]+d)-di-1;
                if(r>=l) ans+=r-l+1;
                lst.emplace(lst3);
                lst.emplace(lst2);
                lst.emplace(lst1);
            }
            ++j;
            if(j==lst.front()) lst.pop();
            tal=di[j]+d;
            if(di[i]<=tal)
            {
                if(lst.size()<3) lst.emplace(i);
                else
                {
                    lst.pop();
                    lst.emplace(i);
                }
            }

        }
    }
    printf("%lld\n",ans);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif // ONLINE_JUDGE

    int c,T;
    read(c),read(T);
    while(T--)
    {
        solve();
    }


    return 0;
}











