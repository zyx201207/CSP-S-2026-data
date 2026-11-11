#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
ll n,m,ans;
ll a[N];
queue<ll> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    q.push(a[1]);
    ll num=0;
    ll cnt=1;
    ans=1;
    for(ll i=2;i<=n;i++)
    {
        q.push(a[i]);
        num+=(i-1)*(a[i]-a[i-1]);
        cnt++;
        while(num>m)
        {
            ll head=q.front();
            num-=a[i]-head;
            q.pop();
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}