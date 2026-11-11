#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],ans;
int Find(int x){
    int l=1,r=x,mid,res;
    while(l<=r){
        int mid=l+r>>1;
        if((x-mid+1)*a[x]-(sum[x]-sum[mid-1])<=m){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,i-Find(i)+1);
    }
    cout<<ans;
}