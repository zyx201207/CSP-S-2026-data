#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],dp[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int st=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1]) dp[st]++;
        else
        {
            dp[st]++;
            st=i+1;
        }
    }
    if(dp[0]==n)
    {
        cout<<n<<'\n';
        return 0;
    }
    sort(a,a+n);
    priority_queue<ll,vector<ll>,greater<ll>> q;
    ll now=0,ans=0;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            cnt++;
            continue; 
        }
        ll x=a[i],z=a[i+1];
        for(int j=1;j<=cnt;j++)
            q.push(x);
        while((z-x)*((ll)q.size())+now>m)
        {
            ll y=q.top();
            q.pop();
            now-=(x-y);
        }
        now+=((ll)q.size())*(z-x);
        ans=max(ans,(ll)q.size()+dp[i+1]);
        cnt=1;
    }
    cout<<ans<<'\n';
    return 0;
}