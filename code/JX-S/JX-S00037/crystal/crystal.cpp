#include<bits/stdc++.h>
using namespace std;
unsigned long long sum[500005];
int main(){
    freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    long long m,a[500005];
    int n,mx=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        int l=1,r=i-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
                mx=max(mx,i-mid+1);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
    }
    cout<<mx;
    return 0;
}
