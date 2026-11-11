#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll n,m;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0;
    ll l=1;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll res=(a[i]-a[i-1]);
        sum+=(i-l)*res;
        while(sum>m){
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}