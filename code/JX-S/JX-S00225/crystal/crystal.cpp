#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll a[n+5];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        for(ll j=1;j<=i;j++){
            if(a[j]-a[i]<=a[j+1]-a[i]){
                m--;
                if(a[i]==a[j]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt-1;
    return 0;
}
