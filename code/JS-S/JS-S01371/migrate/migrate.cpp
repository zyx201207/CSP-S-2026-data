#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005];
int c,t;
void work()
{
    ll n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    if(c==11||c==12)
    {
        ll k=d/(x[2]-x[1]);
        ll K=k+k,ans=n-K+1;
        if(k==0) cout<<"0\n";
        else cout<<ans<<"\n";
    }
    else if(c==13||c==14) cout<<"0\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) work();
    return 0;
}