#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int _=500005;
int n;
ll m;
ll a[_];
int main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,less<ll>());
    int L=1,R=1,ans=0;
    ll req=0;
    for (;R<=n;R++){
        req+=(a[R]-a[R-1])*(R-L);
        while (req>m){
            req-=(a[R]-a[L]);
            L++;
        }
        ans=max(ans,R-L+1);
    }
    cout<<ans;
    return 0;
}
