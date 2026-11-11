#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m,a[500005];
bool check(int x){
    ll sum=0;
    for(int i=1;i<x;i++) sum+=a[i];
    for(int i=0;i+x<=n;i++){
        sum+=a[i+x];
        if(a[i+x]*x-sum<=m) return 1;
        sum-=a[i+1];
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
