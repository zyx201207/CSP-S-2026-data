#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
int a[500005];
int sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int u,l,r,mid,res;
    for(int i=1;i<=n;i++){
        if(i!=n&&a[i+1]==a[i]){
            continue;
        }
        u=i*a[i]-sum[i];
        l=0,r=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(u-(mid*a[i]-sum[mid])<=m){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        res=i-res;
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
