#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
#define mid ((l+r)>>1)
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+10;
int a[maxn],sum[maxn<<2],add[maxn<<2],las[maxm];
int ans[maxm],nxt[maxn];
void pushup(int p)
{
    sum[p]=sum[ls]+sum[rs];
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        sum[p]=l;
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void updatelazy(int p,int l,int r,int k)
{
    sum[p]+=(r-l+1)*k;
    add[p]+=k;
}
void pushdown(int p,int l,int r)
{
    if(add[p]!=0)
    {
        updatelazy(ls,l,mid,add[p]);
        updatelazy(rs,mid+1,r,add[p]);
        add[p]=0;
    }
}
void update(int p,int l,int r,int x,int y,int k)
{
    if(x<=l&&r<=y)
    {
        updatelazy(p,l,r,k);
        return ;
    }
    pushdown(p,l,r);
    if(x<=mid)
    {
        update(ls,l,mid,x,y,k);
    }
    if(y>mid)
    {
        update(rs,mid+1,r,x,y,k);
    }
    pushup(p);
}
int query(int p,int l,int r,int x)
{
    if(l==r)
    {
        sum[p]=max(0ll,sum[p]);
        return sum[p];
    }
    pushdown(p,l,r);
    int res=0;
    if(x<=mid)
    {
        res+=query(ls,l,mid,x);
    }
    else
    {
        res+=query(rs,mid+1,r,x);
    }
    return res;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        if(las[a[i]])
        {
            nxt[las[a[i]]]=i;
        }
        las[a[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        if(nxt[i])
        {
            int k=query(1,1,n,i);
            update(1,1,n,i,nxt[i]-1,-k);
        }
    }
    for(int i=1;i<=n;++i)
    {
        int k=query(1,1,n,i);
        ans[a[i]]+=k;
    }
    for(int i=1;i<=m;++i)
    {
        printf("%lld ",ans[i]);
    }
    return 0;
}