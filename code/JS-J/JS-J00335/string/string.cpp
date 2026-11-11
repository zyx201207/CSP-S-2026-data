#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans=0;
ll a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]<=a[r]){
            a[r]-=a[l];
            a[l]=0;
            l++;
            if(a[r]==0){
                r--;
            }
        }
        else if(a[r]<=a[l]){
            a[l]-=a[r];
            a[r]=0;
            r--;
            if(a[l]==0){
                l++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
