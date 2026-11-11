#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans=0;
ll a[200100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(ll b=30;b>=0;b--)
    {
        ll cand=(ans|(1ll<<b));
        ll cnt=0;
        for (ll x : a)
        {
            if((x&cand)==cand){
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans=cand;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}