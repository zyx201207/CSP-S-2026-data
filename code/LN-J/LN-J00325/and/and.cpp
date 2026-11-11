#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    if(m==1){
        printf("%lld",a[n]);
        return 0;
    }
    long long ans;
    if(m==n){
        ans=a[n];
        for(long long i=1;i<=n;i++){
        ans&=a[i];
    }
        printf("%lld",ans);
        return 0;
    }

    if(m==2){
            ans=-1;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                long long k=a[i]&a[j];
                ans=max(ans,k);
            }
        }
        printf("%lld",ans);
        return 0;
    }

    ans=a[n];
    for(long long i=1;i<m;i++){
        ans&=a[n-i];
    }

    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
