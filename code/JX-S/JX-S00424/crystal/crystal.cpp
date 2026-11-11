#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510000],add[510000];
bool cmp(long long x,long long y){
    return x<y;
}
int rf(int x){
    int l=1,r=x,mid;
    while(l<r){
        int mid=(l+r)/2;
        if(a[x]*1ll*(x-mid+1)-(add[x]-add[mid-1])>m){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.our","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        add[i]=add[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-rf(i)+1);
    }
    printf("%d",ans);
    return 0;
}
