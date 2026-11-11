#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m;
ll a[N],s[N];
//unordered_map<ll,ll>mp,id,tag;
ll id[N],mp[N],p[N];
int check(int mid)
{
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        ll now=mp[p[i]];
        ll lst=mid-now;
        if(lst<=0)
        {
            flag=1;
            break;
        }
        ll pre=id[i]-lst;
        if(pre<=0)continue;
        ll ans=a[i]*lst-(s[id[i]-1]-s[pre-1]);
        if(ans<=m)flag=1;
        //if(mid==316935 &&ans<=m)cout<<"ans="<<ans<<' '<<lst<<' '<<pre<<' '<<i<<endl;
    }
    return flag;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;//19768503
    //cout<<n<<' '<<m<<endl;
   //return 0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    id[1]=1;mp[1]=1;int now=1;p[1]=now;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            id[i]=id[i-1];
            mp[now]++;
            p[i]=now;
        }
        else
        {
            now++;
            id[i]=i;
            mp[now]=1;
            p[i]=now;
        }
    }
    //for(int i=1;i<=n;i++)
     //   if(!tag[a[i]])id[a[i]]=i,tag[a[i]]=1;
    ll l=1,r=n,ans=0;
    while(l<=r)
    {
        ll mid=l+r>>1;
        //cout<<mid<<' '<<check(mid)<<endl;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
