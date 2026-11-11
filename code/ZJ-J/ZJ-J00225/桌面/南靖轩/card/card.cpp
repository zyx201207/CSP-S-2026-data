#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
constexpr int maxm=3e5+10;
int n,m,a[maxn],c[maxn],res[maxn],A,B,fst[maxm],lst[maxm],cnt[maxm];
vector<int> pos[maxm];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        ++cnt[a[i]];
        if(!fst[a[i]]) fst[a[i]]=i;
        lst[a[i]]=i;
        pos[a[i]].emplace_back(i);
    }
    for(int i=1;i<n;++i)
    {
        if(a[i]>a[i+1]) A=1;
    }
    if(m==1)
    {
        printf("%lld",n);
    }
    else if(m==2)
    {
        for(int i=1;i<=n;++i)
        {
            if(a[n]==1)
            {
                ++res[1];
                if(a[i]==2) ++res[2];
            }
            else
            {
                ++res[2];
                if(a[i]==1) ++res[1];
            }
        }
        for(int i=1;i<=m;++i)
        {
            printf("%lld ",res[i]);
        }
    }
    else if(n<=5000)
    {
        vector<vector<int>> stk(m+1);
        int l=0,r=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=a[i-1])
            {
                for(int j=1;j<=m;++j) stk[j].clear();
                for(int j=i;j<=n;++j)
                {
                    if(!stk[a[j]].empty())
                    {
                        for(int k=stk[a[j]].back();k<j;++k)
                        {
                            if(!stk[a[k]].empty())
                            {
                                if(stk[a[k]].back()!=k) k=stk[a[k]].back();
                                stk[a[k]].pop_back();
                            }
                        }   
                    }
                    stk[a[j]].emplace_back(j);            
                }   
            }
            for(int j=1;j<=m;++j)
            {
               if(!stk[j].empty()) ++res[j];
            }
        }
        for(int i=1;i<=m;++i)
        {
            printf("%lld ",res[i]);
        }
    }
    else if(!A)
    {
        for(int i=1;i<=m;++i)
        {
            printf("%lld ",pos[i].back());
        }
    }
    else
    {
        vector<vector<int>> stk(m+1);
        int l=0,r=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=a[i-1])
            {
                for(int j=1;j<=m;++j) stk[j].clear();
                for(int j=i;j<=n;++j)
                {
                    if(!stk[a[j]].empty())
                    {
                        for(int k=stk[a[j]].back();k<j;++k)
                        {
                            if(!stk[a[k]].empty())
                            {
                                if(stk[a[k]].back()!=k) k=stk[a[k]].back();
                                stk[a[k]].pop_back();
                            }
                        }   
                    }
                    stk[a[j]].emplace_back(j);            
                }   
            }
            for(int j=1;j<=m;++j)
            {
               if(!stk[j].empty()) ++res[j];
            }
        }
        for(int i=1;i<=m;++i)
        {
            printf("%lld ",res[i]);
        }
    }
    return 0;
}
