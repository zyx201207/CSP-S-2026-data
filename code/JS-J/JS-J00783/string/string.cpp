#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>s[i];
    }
    ll l=0,r=n-1;
    ll cnt=0;
    while(l<r){
        if(s[r]!=s[l]){
            cnt+=min(a[r],a[l]);
        }
        if(a[r]<a[l]){
            a[l]-=a[r];
            r--;
        }
        else if(a[r]>a[l]){
            a[r]-=a[l];
            l++;
        }
        else{
            a[r]=0;
            a[l]=0;
            l++;
            r--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
