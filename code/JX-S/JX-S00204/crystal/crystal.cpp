#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll n,m,ans=-1;
ll x;

vector<ll> a;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        ll cnt=0,m1=m;
        for(int j=i;j>=0;j--){
            m1-=(a[i]-a[j]);
            if(m1<0){
                break;
            }
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
