#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n;
ll m;
int a[N];
ll sum[N];
int ans=0;
ll tmp=0;

bool check(int k){
    for(int s=1;s<=n-k+1;++s){
        int t=s+k-1;
        tmp=1ll*(k-1)*a[t]-(sum[t-1]-sum[s-1]);
        if(tmp<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}
