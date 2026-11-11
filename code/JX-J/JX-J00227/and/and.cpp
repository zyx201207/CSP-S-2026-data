#include <bits/stdc++.h>;
using namespace std;
#define ll long long
ll ans=INT_MIN;
ll ans2;
int n,m;
const int N=2e5+10;
ll a[N];
void dfs(int now,int step,ll cnt)
{
    if(step==m)
    {
        ans=max(ans,cnt);
        return;
    }
    if(now>n)
    {
        return;
    }
    dfs(now+1,step,cnt);
    if(step==0) dfs(now+1,step+1,a[now]);
    else
    {
        int x;
        x=cnt&a[now];
        dfs(now+1,step+1,x);
    }
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
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            ans2&=a[i];
        }
        cout<<ans2;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
