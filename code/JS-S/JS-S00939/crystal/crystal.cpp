#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long n,m;
long long a[maxn],b[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int f=0;
    for(long long i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        if(i>1&&b[i]!=b[i-1]&&f==0) f=1;
    }
    if(f==0){
        long long w=0;
        long long i=1;
        while(w+b[i]*i<=m){
            w+=b[1]*i;
            i++;
        }
        printf("%lld\n",i);
        return 0;
    }
    long long ans=1;
    for(long long i=1;i<n;i++){
        if(i+ans-1>n) break;
        long long w=0;
        long long j=i;
        while(w+(j-i+1)*b[j]<=m&&j<n){
            w+=(j-i+1)*b[j];
            j++;
        }
        ans=max(ans,j-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}
