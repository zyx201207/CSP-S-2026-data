#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int sum[500010];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        maxn=max(maxn,i-ans+1);
    }
    cout<<maxn<<"\n";
    return 0;
}