#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,d[500005],a[500005],l,r;
int main(){
    freopen("./crystal.in","r",stdin);
    freopen("./crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    r=1;
    l=1;
    while(r<=n){
        while(a[r]*(r-l+1)-(d[r]-d[l-1])>m&&l<=r){
            //cout<<l<<" "<<r<<" "<<a[r]*(r-l+1)<<" "<<(d[r]-d[l-1])<<"\n";
            l++;
        }
        if(l<=r){
            ans=max(ans,r-l+1);
        }
        r++;
    }
    cout<<ans;
    return 0;
}
