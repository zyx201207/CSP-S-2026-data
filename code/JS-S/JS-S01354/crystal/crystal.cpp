#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],c[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            int target=a[i]*mid;
            int now=c[i]-c[i-mid];
            if(target-now<=m){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        // cout<<i<<':'<<l<<'\n';
        ans=max(ans,l);
    }
    cout<<ans<<' ';
    return 0;
}