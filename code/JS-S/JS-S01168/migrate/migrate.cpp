#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define mp make_pair
#define ll long long
#define pii pr<int,int>
using namespace std;
int tr[2000006];
ll a[2000006];
ll cs[2000006],co[2000006];
ll to[2000006];
void sl()
{
    int n;
    ll d;
    cin>>n>>d;
    int cr=1;
    for(int i=1;i<=n;i++) cin>>a[i],cs[i]=0,co[i]=0,to[i]=0;
    for(int i=1;i<=n;i++)
    {
        while(cr<n&&a[cr+1]<=a[i]+d) cr++;
        tr[i]=cr;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(tr[i]==i) continue;
        ans+=(tr[i]-max(tr[i-1],i))*to[i];
        if(i>1) ans+=cs[i]*(tr[i-1]-max(tr[i-2],i));
        if(tr[i-1]==tr[i]&&tr[i-2]<tr[i-1]) to[tr[i]]+=cs[i];
        if(tr[i-1]+1<tr[i]) cs[tr[i]]+=co[i];
        if(tr[i-1]<tr[i]) co[tr[i]]+=co[i],to[tr[i]]+=to[i];
        cs[tr[i]]++;
        co[tr[i]]++;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cd,t;
    cin>>cd>>t;
    while(t--) sl();
    return 0;
}
