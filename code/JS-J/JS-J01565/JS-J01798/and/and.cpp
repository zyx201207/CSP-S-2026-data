#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        ll mx=-1;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }else if(m==2){
        ll mx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout<<mx;
    }else{
        ll mx=-1;
        ll t;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                t=(a[i]&a[j]);
                for(int x=j+1;x<=n;x++){
                    mx=max(mx,(t&a[x]));
                }
            }
        }
        cout<<mx;
    }
    return 0;
}
