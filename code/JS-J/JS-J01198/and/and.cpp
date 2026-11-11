#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxa=0;
void dfs(int w,int k,int z)
{
    if(k==0)
    {
        maxa=max(maxa,z);
        return;
    }
    if(w>n)
    {
        return;
    }
    dfs(w+1,k,z);
    dfs(w+1,k-1,z&a[w]);
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int ma=0;
        for(int i=1;i<=n;i++)
        {
            ma=max(ma,a[i]);
        }
        cout<<ma;
        return 0;
    }
    if(m==n)
    {
        int cnt=a[1];
        for(int i=2;i<=n;i++)
        {
            cnt&=a[i];
        }
        cout<<cnt;
        return 0;
    }
    if(n<=4000)
    {
        dfs(1,m,2147483647);
        cout<<maxa;
    }
    else
    {
        if(m==n-1);
        {
            for(int i=1;i<=n;i++)
            {
                int cnt=3247483647;
                for(int j=1;j<=n;j++)
                {
                    if(j==i)
                    {
                        continue;
                    }
                    cnt&=a[j];
                }
                maxa=max(maxa,cnt);
            }
            cout<<maxa;
            return 0;
        }
        sort(a+1,a+1+n);
        cout<<a[n+1-m];
    }
    return 0;
}
