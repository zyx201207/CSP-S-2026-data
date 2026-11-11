#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=5e5+13;
constexpr int maxm=3e5+13;

int n,m;
int a[maxn];
bool vis[maxm];
int cnt[maxm];
int ans[maxm];
void sol_small()
{
    for(int st=1; st<=n; ++st)
    {
        vector<int>stk;
        for(int i=st; i<=n; ++i)
        {
            if(!vis[a[i]])
            {
                stk.push_back(a[i]);
                vis[a[i]]=1;
            }
            else
            {
                while(stk.back()!=a[i])
                {
                    vis[stk.back()]=0;
                    stk.pop_back();
                }
            }
        }
        for(int x:stk)
        {
            vis[x]=0;
            ++ans[x];
            //printf("%d ",x);
        }
        //printf("\n");
    }
    for(int i=1; i<=m; ++i)
    {
        printf("%d ",ans[i]);
    }
}
int last[maxm];
void sol_small2()
{
    for(int i=n;i>=1;--i)
    {
        if(!last[a[i]])
        {
            last[a[i]]=i;
        }
        ++cnt[a[i]];
    }
    for(int c=1;c<=m;++c)
    {
        int st=last[c];
        vector<int>stk;
        for(int i=st; i<=n; ++i)
        {
            if(!vis[a[i]])
            {
                stk.push_back(a[i]);
                vis[a[i]]=1;
            }
            else
            {
                while(stk.back()!=a[i])
                {
                    vis[stk.back()]=0;
                    stk.pop_back();
                }
            }
        }
        for(int x:stk)
        {
            vis[x]=0;
            ans[x]+=cnt[x];
            //printf("%d ",x);
        }
        //printf("\n");
    }
    for(int i=1; i<=m; ++i)
    {
        printf("%d ",ans[i]);
    }
}
int nxt[maxn];
int dp[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
    }
//    if(n*n<=50000000)
//    {
//        sol_small();
//        return 0;
//    }
//    if(n*m<=50000000)
//    {
//        sol_small2();
//        return 0;
//    }
    for(int i=n;i>=1;--i)
    {
        if(last[a[i]])
        {
            nxt[i]=last[a[i]];
        }
        last[a[i]]=i;
    }
    for(int i=1;i<=n;++i)
    {
        ++dp[i];
        if(nxt[i])
        {
            dp[nxt[i]]+=dp[i];
        }
        else
        {
            ans[a[i]]=dp[i];
            dp[i+1]+=dp[i];
        }
    }
    for(int i=1;i<=m;++i)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}

