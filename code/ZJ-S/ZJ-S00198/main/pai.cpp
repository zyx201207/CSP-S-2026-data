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

constexpr int maxn = 5e5+10;

int wi[maxn];
int di[maxn];
int sum_i[maxn];
int sum[maxn];
int n,m;


inline void add(int s[],int x,const int &k)
{
    while(x<=n)
    {
        s[x]+=k;
        x+=x & -x;
    }
}

inline int query(int s[],int x)
{
    int ret=0;
    while(x)
    {
        ret+=s[x];
        x-=x& -x;
    }
    return ret;
}

inline bool check(const int &id,int x)
{
    int ans=query(sum_i,id)-query(sum_i,x);
    ans-=query(sum,id)-query(sum,x);
    return ans<=m;
}

inline int binans(const int &id,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=l+((r-l)>>1);
        if(!check(id,mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return id-l+1;
}

inline void bl()
{
    int ans=1;
    int use=0;
    for(int i=1;i<=n;++i)
    {
        use=0;
        for(int j=i-1;j>=1;--j)
        {
            use+=wi[i]-wi[j];
            if(use<=m) ans=max(ans,i-j+1);
        }
    }
    printf("%lld\n",ans);
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("crystal.in","r",stdin);
    freopen("crystal.pai","w",stdout);
    #endif // ONLINE_JUDGE

    read(n),read(m);
    for(int i=1;i<=n;++i)
    {
        read(wi[i]);
    }
    sort(wi+1,wi+1+n);
    for(int i=1;i<=n;++i)
    {
        // cerr<<wi[i]<<' ';
        di[i]=wi[i]-wi[i-1];
        add(sum,i,di[i]);
        add(sum_i,i,di[i]*i);
    }

//    int id=5000,x=5000;
//    int ans=query(sum_i,id)-query(sum_i,x);
//    ans-=query(sum,id)-query(sum,x);
//    printf("%lld",ans);
//
//    return 0;

    bl();
    return 0;

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,binans(i,1,i));
    }
    printf("%lld\n",ans);


    return 0;
}











