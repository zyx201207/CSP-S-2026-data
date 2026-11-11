#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans;
queue<ll>q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        q.push(a[i]);
        if(q.size()*a[i]-sum>m)while(!q.empty()&&q.size()*a[i]-sum>m)sum-=q.front(),q.pop();
        ans=max(ans,(ll)q.size());
    }
    cout<<ans<<"\n";
    return 0;
}