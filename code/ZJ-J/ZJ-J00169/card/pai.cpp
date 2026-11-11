#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int maxn = 5e5+10;

inline void read(int &x)
{
    x=0;
    signed f=1,c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    x*=f;
}

int wi[maxn];
int cnt[maxn];
int ans[maxn];
vector<bool> vis(maxn,0);

int stk[5010];

inline void bl(int n,int m)
{
    for(int st=1;st<=n;++st)
    {
        int top=0;
        for(int i=st;i<=n;++i)
        {
            if(!vis[wi[i]])
            {
                vis[wi[i]]=1;
                stk[++top]=wi[i];
            }
            else
            {
                while(stk[top]!=wi[i])
                {
                    vis[stk[top--]]=0;
                }
            }
        }
        while(top)
        {
            ++cnt[stk[top]];
            vis[stk[top--]]=0;
        }
    }
    for(int i=1;i<=m;++i)
    {
        printf("%lld ",cnt[i]);
    }
}

int zt[maxn],fa[maxn];
int lst[maxn];

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("card.in","r",stdin);
    freopen("card.pai","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    read(n),read(m);
    for(int i=1;i<=n;++i)
    {
        read(wi[i]);
    }

    if(n<=5000)
    {
        bl(n,m);
        return 0;
    }

    int top=0; // zt;
    for(int i=n;i;--i)
    {
        if(!lst[wi[i]])
        {
            fa[top+1]=top;
            vis[top+1]=1;
        }
        else fa[top+1]=lst[wi[i]];
        zt[++top]=wi[i];
        lst[wi[i]]=top;
        cnt[top]=1;
    }

    for(;top;--top)
    {
        if(fa>0) cnt[fa[top]]+=cnt[top];
        if(vis[top]) ans[zt[top]]+=cnt[top];
    }
    for(int i=1;i<=m;++i)
    {
        printf("%lld ",ans[i]);
    }


    return 0;
}
















