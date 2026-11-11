#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void cmax(int &x,int y)
{
    x=max(x,y);
}
void cmin(int &x,int y)
{
    x=min(x,y);
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=1e6+5;
int sub,tc,n,m,dep[N],low[N],fa[N],s[N];
vector<int> v[N];
void idfs(int x,int F)
{
    low[x]=dep[x]=dep[F]+1;fa[x]=F;
    for(int y:v[x])
    {
        if(y==F)
            continue;
        idfs(y,x);
        cmin(low[x],low[y]);
    }
}
void dfs(int x,int r)
{
    s[x]=0;
    if(low[x]-dep[x]>=r)
        s[x]++;
    for(int y:v[x])
    {
        if(y==fa[x])
            continue;
        s[x]+=s[y];
    }
}
bool check(int r)
{
    dfs(1,r);
    if(s[1]<=m)
        return 1;
    return 0;
}
signed main()
{
    freopen("sub.in","r",stdin);
    freopen("sub.out","w",stdout);
    sub=read(),tc=read();
    while(tc--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=1,x,y;i<n;i++)
        {
            x=read(),y=read();
            v[x].push_back(y);
            v[y].push_back(x);
        }
        idfs(1,0);
        int l=1,r=n,mid,ans=n;
        while(l<=r)
        {
            mid=l+r>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        write(ans);puts("");
    }
    return 0;
}
