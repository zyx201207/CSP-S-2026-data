#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],delta[500005],pre[500005],times[500005];


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    pre[1]=delta[1]=times[1]=0;
    for(ll i=2;i<=n;i++){
        delta[i]=a[i]-a[i-1];
        pre[i]=pre[i-1]+delta[i];
        times[i]=(i-1)*(pre[i]-pre[i-1])+times[i-1];
    }

    ll l=1,r=n;
    while(l<r){
        ll mid = (l+r+1)/2;
        if(times[mid]<=m){
            l=mid;
        }
        else r=mid-1;
    }

    cout<<l<<endl;
    return 0;
}
