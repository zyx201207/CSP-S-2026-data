#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
        b[i]=1;
    }
    sort(a,a+n);
    for(long long i=n-1;i>=0;i--){
        long long tmp=m;
        for(long long j=i-1;j>=0;j--){
            tmp-=a[i]-a[j];
            if(tmp>=0)b[i]++;
            else break;
        }
    }
    long long maxx=b[0];
    for(long long i=0;i<n;i++){
        maxx=max(b[i],maxx);
    }
    printf("%lld",maxx);
    return 0;
}
