#include<bits/stdc++.h>
using namespace std;
const int MAXN =500050;
typedef unsigned long long ll;

ll n,m,c[MAXN],s[MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll q=0,h=0;
    cin>>n>>m;
    ll mm=m;
    for(ll i=1;i<=n;i++)
    {
        long long tmp;
        cin>>tmp;
        c[i]=tmp+1000000000010;
    }
    sort(c+1,c+n+1);
    bool ca=1,cb=1;
    for(ll i=1;i<=n;i++)
    {
        if(i!=c[i]-100010)
        {
            ca=0;
            break;
        }
    }
    for(ll i=2;i<=n;i++)
    {
        ll d=c[2]-c[1];
        if(c[i]-c[i-1]!=d)
        {
            cb=0;
            break;
        }
    }
    if(ca)
    {
        for(ll i=1;i<=n;i++)
        {
            if(((i-1)*i)/2>m)
            {
                cout<<i-1<<"\n";
                return 0;
            }
        }
        cout<<n<<"\n";
        return 0;
    }
    if(cb)
    {
        for(ll j=1;j<=n;j++)
       {
            if(((j-1)*j)/2>m/(c[2]-c[1]))
            {
                cout<<j-1<<"\n";
                return 0;
            }
        }
        cout<<n<<"\n";
        return 0;
    }
    ll ans=0;

    for(ll l=1;l<=n-ans;l++)
    {
        for(ll r=l+ans;r<=n;r++)
        {
            ll tot=0;
            for(ll z=l;z<r;z++)
            {
                tot+=c[r]-c[z];
                //cout<<l<<' '<<r<<' '<<z<<' '<<tot<<"\n";
                if(tot>mm) break;
            }
            if(tot<=mm) 
            {
                //cout<<l<<' '<<r<<' '<<tot<<"\n";
                ans=max(r-l,ans);
            }
            else break;
        }
    }
    cout<<ans+1<<'\n';
    return 0;
}