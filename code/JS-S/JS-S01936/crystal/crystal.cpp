#include<iostream>
#include<cstdio>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    #ifndef PSD
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    vector<long long> v(n+1),sum(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(v.begin()+1,v.end());
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i];
    auto check=[&](int k){
        long long ans=9e18l;
        for(int i=k;i<=n;i++)
            ans=min(ans,v[i]*k-(sum[i]-sum[i-k]));
        return ans<=m;
    };
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
