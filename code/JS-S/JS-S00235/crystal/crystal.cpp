#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;
ll n,m;
ll a[N];
ll s[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }

    ll ans;
    for(int i=1;i<=n;i++){
        if((i-1)*a[i]-s[i-1]>m){
            break;
        }
        ans=i;
    }
    cout<<ans;

    if(n>500000){
        ll c=a[2]-a[1];
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum+=c*i;
            if(sum>m){
                cout<<i;
            }
        }
    }

    return 0;
}
