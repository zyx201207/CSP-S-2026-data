#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N],ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                ans+=a[l];
                l++;
                r--;
            }
            else{
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
        else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                l++;
                r--;
            }
            else{
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
