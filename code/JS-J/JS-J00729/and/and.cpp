#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ans=-1,mx=-1,yu;
    cin>>n>>m;
    ll a[200005]={0};
    cin>>a[0];
    yu=a[0];
    for(ll i=1;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        yu&=a[i];
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        cout<<yu;
        return 0;
    }
    if(m==2){
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll su=a[i];
                su&=a[j];
                ans=max(ans,su);
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a,a+n);
    int anss=a[n-1];
    for(int i=n-2,j=1;j<m;i--,j++){
        anss&=a[i];
    }
    cout<<anss;
    return 0;
}
