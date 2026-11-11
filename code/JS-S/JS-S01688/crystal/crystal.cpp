#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long m;
long long a[500005],b[500005],c[500005],d[500005];
long long mf(int i){
    long long l=i,r=n;
    long long mid=(l+r)/2;
    while(l<=r){
        mid=(l+r)/2;
        long long ma=c[mid]-c[i]+(mid-i)*a[mid]-(d[mid]-d[i]);
        if(m<ma){
            r=mid-1;
        }
        if(m>=ma){
            l=mid+1;
        }
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    for(int i=3;i<=n;i++){
        c[i]+=c[i-1];
    }

    for(int i=1;i<=n;i++){
        ans=max(ans,mf(i)-i);
    }
    printf("%d",ans);
    return 0;
}
