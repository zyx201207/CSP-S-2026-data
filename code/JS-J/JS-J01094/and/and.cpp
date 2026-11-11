#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int n,m;
int mx;
void dfs(int now,int cnt)
{
    if(now>n)
    {
        if(cnt==m)
        {
            int tot=b[0];
            cout<<b[0]<<" ";
            for(int i=1;i<cnt;i++)
            {
                tot=tot&b[i];
                cout<<b[i]<<" ";
            }
            cout<<endl;
            mx=max(mx,tot);
        }
        return ;
    }
    b[cnt]=a[now];
    dfs(now+1,cnt+1);
    dfs(now+1,cnt);
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
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        int tot=a[1];
        for(int i=2;i<=n;i++)
        {
            tot=tot&a[i];
        }
        cout<<tot;
        return 0;
    }
    if(m==2)
    {
        int mi=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    mi=max(mi,a[i]&a[j]);
                }
            }
        }
        cout<<mi;
        return 0;
    }
    if(n>2010)
    {
        long long tot=a[1];
        for(int i=2;i<=n;i++)
        {
            tot=tot&a[i];
        }
        cout<<tot;
        return 0;
    }
    dfs(1,0);
    cout<<mx;
    return 0;
}
