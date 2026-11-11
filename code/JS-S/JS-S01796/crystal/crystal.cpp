#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ansz=0;
    ll ans=0;
    ll cnt=0;
    ll l=1;
    for(ll i=1;i<=n;i++){
        cnt+=ans*(abs(a[i]-a[i-1]));
        if(cnt<=m){
            ans++;
            ansz=max(ansz,ans);
        }
        else{
            while(cnt>m){
                ans--;
                ansz=max(ans,ansz);
                cnt-=abs(a[i]-a[l]);
                l++;
            }
        }
    }
    cout<<ansz;
    return 0;
}
