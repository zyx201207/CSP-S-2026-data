#include <bits/stdc++.h>
using namespace std;

int mp[200010];
long long a[200010],n,m,maxn=-1;

void dfs(long long step)
{
    if(step>m)
    {
        long long p=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==1)
            {
                p&=a[i];
            }
        }
        maxn=max(maxn,p);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
        {
            mp[i]=1;
            dfs(step+1);
            mp[i]=0;
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(m==1) cout << *max_element(a+1,a+n+1);
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout << maxn;
    }
    else if(m==n)
    {
        long long p=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
        for(int i=1;i<=n;i++)
        {
            p&=a[i];
        }
        cout << p;
    }
    else if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            long long p=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2-1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    p&=a[j];
                }
            }
            maxn=max(maxn,p);
        }
        cout << maxn;
    }
    else{
        dfs(1);
        cout << maxn;
    }
    return 0;
}
