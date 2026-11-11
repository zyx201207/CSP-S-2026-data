#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500011];
long long sum[500011];
unordered_map<long long,int> mp;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        mp[a[i]]++;
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    long long last=-(1<<30);
    for(int i=1;i<=n;++i){
        if(a[i]==last) continue;
        last=a[i];
        int res=mp[a[i]];
        int l=0,r=i-1;
        while(l<r){
            // cerr<<l<<' '<<r<<'\n';
            int mid=(l+r+1)/2;
            long long ad=mid*a[i]-(sum[i-1]-sum[i-mid-1]);
            if(ad<=m) l=mid;
            else r=mid-1;
        }
        res+=l;
        //  cerr<<i<<' '<<l<<' '<<mp[a[i]]<<' '<<res<<'\n';
        if(res>ans) ans=res;
    }
    cout<<ans;
}