#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<=r){
            int mid=(l+r)>>1;
            int x=sum[i-1]-sum[mid-1];
            int ned=a[i]*(i-mid)-x;
            if(ned>m){
                l=mid+1;
            }
            else{
                ans=max(ans,i-mid+1);
                r=mid-1;
            }
        }
    }
    cout<<ans;
    return 0;
}