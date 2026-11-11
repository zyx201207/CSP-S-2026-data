#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],f[500010],n,m;
inline bool check(int i,int j){
    if(a[i]*(i-j+1)-f[i]+f[j-1]<=m)return 1;
    return 0;
}
inline int erf(int i){
    int l=1,r=i,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(i,mid))r=mid-1;
        else l=mid+1;
    }
    return i-r;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        ans=max(ans,erf(i));
        if(ans>i)break;
    }
    cout<<ans;
    return 0;
}
// 20min
