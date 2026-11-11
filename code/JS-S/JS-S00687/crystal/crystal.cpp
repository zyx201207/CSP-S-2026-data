#include<bits/stdc++.h>
using namespace std;
int n,r,l;
long long m,a[500005],b[500005];
bool check(int mid){
    long long s=2e18;
    for(int i=1;i<=n-mid+1;i++){
        if(mid%2) s=min(s,b[i+mid-1]-b[i-1+mid/2]-b[i+mid/2]+b[i-1]);
        else s=min(s,b[i+mid-1]-b[i-1+mid/2]-b[i-1+mid/2]+b[i-1]);
    }
    return s<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    l=1,r=n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
