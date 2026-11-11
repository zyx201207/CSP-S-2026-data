#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],l=1,r=1,ans,s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ans=1;
    s=0;
    while(r<n){
        if((s+(r-l+1)*(a[r+1]-a[r]))<=m){
            s+=(r-l+1)*(a[r+1]-a[r]);
            ++r;
            ans=max(ans,r-l+1);
        }else{
            s-=(a[r]-a[l]);
            ++l;
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans;
    return 0;
}
