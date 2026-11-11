#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
const int N=5e5+5;
ll target,idx;
ll a[N];
ll b[N];
int main(){
   // freopen("crystal.in","r",stdin);
   // freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    idx=n/2+1;
    target=a[idx];
    ll ans=0;
    for(int i=1;i<=n;i++){
        a[i]-=target;
        if(a[i]<0){
            b[i]=-a[i];
        }else{
            b[i]=a[i];
        }
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n&&m>=0;i++){
        m-=b[i];
        if(m<0) break;
        ans++;
    }
    cout<<ans;
    return 0;
}
