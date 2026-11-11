#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],n,m;
bool judge()
{
    int f=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<a[i-1]) return false;
    }
    return true;
}
void solve()
{
    int sum=1,s=0;
    ans[a[1]]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            ans[a[i-1]]=sum+s;
            s+=sum;
            sum=1;
            continue;
        }
        sum++;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(judge())
    {
        solve();
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        return 0;
    }
    for(int u=1;u<=n;u++)
    {
        int l=u,r=n;
        while(l<=n)
        {
            if(a[l]==a[r])
            {
                ans[a[r]]++;
                l=r+1;
                r=n;
                continue;
            }
            r--;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
