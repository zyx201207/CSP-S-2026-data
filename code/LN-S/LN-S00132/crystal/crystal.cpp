#include<bits/stdc++.h>
using namespace std;

const long long N=5e5+10;
long long n,m;
long long a[N];
long long b[N];
long long ans;
long long sum;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<n;i++){
        b[i]=b[i-1]+(a[i]-a[i+1]);
    }
    sort(b+1,b+n);
    for(long long i=1;i<=n;i++){
        if(sum+b[i]<=m){
            ans=i;
            sum+=b[i];
        }else{
            ans=i;
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}
