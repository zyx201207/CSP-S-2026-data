#include<bits/stdc++.h>
using namespace std;
long long p=0,n,l,r,mid;
long long m,a[500005],q[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++){
        q[i]=q[i-1]+(i-1)*(a[i]-a[i-1]);
        l=1,r=i-1;
        while(l<r){
            mid=ceil(l+r)/2;
            if(l==mid) break;
            if(q[i]-(i-mid-1)*(a[i]-a[i-1])-q[i-mid]<=m){
                l=mid;
            } else r=mid-1;
        }
       if(q[i]-(i-r-1)*(a[i]-a[i-1])-q[i-r]<=m) p=max(p,r);
       else p=max(p,l);
    }
    if(p!=0) cout<<p+1;
    else cout<<0;
    return 0;
}
