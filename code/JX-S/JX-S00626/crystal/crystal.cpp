#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5E5+15;
ll n,m,a[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool zrx_nb=0;
    ll ma=a[1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(m>=a[n]-a[i]){
            m-=a[n]-a[i];
            ans++;
        }
        else break;
    }
    cout<<ans;
    return 0;
}
