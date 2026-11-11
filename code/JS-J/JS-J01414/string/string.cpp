#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n;
ll a[200005];
char b[200005];

int main(){
    freopen("string.out","w",stdout);
    freopen("string.in","r",stdin);
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i]>>b[i];
    }
    ll l=1,r=n,ans=0;
    while(l<r){
        if(a[l]>a[r]){
            if(b[l]!=b[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }else{
            if(b[l]!=b[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}