#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int htw[500010];
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    htw[1]=0;
    for(int i=2;i<=n;i++){
        htw[i]=htw[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    for(int i=2;i<=n;i++){
        int l=1,r=i;
        int ansss=1;
        while(l<r){
            int mid=(l+r)/2;
            if(htw[i]-htw[mid]-(a[i]-a[mid])*(mid-1)<=m){
                r=mid;
                ansss=i-mid+1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,ansss);
    }
    cout<<ans;
    return 0;
}
