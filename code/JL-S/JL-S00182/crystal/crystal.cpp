#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,m;
long long sum;
long long cnt;
long long ans;
long long a[N];

bool check(long long x){
    sum=0;
    cnt=0;
    for(long long j=1;j<x;j++){
        if(a[x]-a[j]+sum<=m){
            sum+=a[x]-a[j];
            cnt++;
        }
    }
    if(cnt+1<ans) return false;
    else{
        ans=cnt+1;
        return true;
    }

}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    sort(a+1,a+1+n);

    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
