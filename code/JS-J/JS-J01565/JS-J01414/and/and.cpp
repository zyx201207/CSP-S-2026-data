#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m;
ll a[200005];
ll f[200005];
ll sum[200005];
int main(){
    freopen("and.out","w",stdout);
    freopen("and.in","r",stdin);
    cin>>n>>m;
    cin>>a[1];
    for(ll i=2;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[1]=a[1];
    for(ll i=2;i<=n;++i){
        sum[i]=sum[i-1]&a[i];
    }
    memset(f,-1,sizeof(f));
    for(ll i=1;i<=n;i++){
        for(ll j=m;j>=1;j--){
            if(f[j]!=-1)f[j]=max(f[j],f[j-1]&a[i]);
            else f[j]=sum[j];
        }
    }
    cout<<f[m];
    return 0;
}