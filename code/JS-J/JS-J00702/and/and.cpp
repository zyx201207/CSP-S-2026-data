#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
ll n,k;
bool vis[200010];
ll ans=INT_MIN;
ll jilu=-1;
void dfs(ll pos)
{
    ll huisu;
    if(pos==k+1)
    {
        ans=max(ans,jilu);
        return;
    }
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            huisu=jilu;
            if(jilu==-1) jilu=a[i];
            else jilu=jilu&a[i];
            vis[i]=true;
            dfs(pos+1);
            vis[i]=false;
            jilu=huisu;
        }
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    memset(vis,false,sizeof vis);
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
