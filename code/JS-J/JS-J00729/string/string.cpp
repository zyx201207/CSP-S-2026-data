#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll a[200005];
    char b[200005];
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll i=0,j=n-1,ans=0;
    while(i<j){
        if(b[i]!=b[j]){
            ans+=min(a[i],a[j]);
            if(a[i]<a[j]){
               a[j]-=a[i];
               i++;
            }
            else{
                a[i]-=a[j];
                j--;
            }
        }
        else {
            if(a[i]<a[j]){
               a[j]-=a[i];
               i++;
            }
            else{
                a[i]-=a[j];
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
