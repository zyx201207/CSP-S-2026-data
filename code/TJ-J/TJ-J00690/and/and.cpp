#include<bits/stdc++.h>
using namespace std;

long long a[222222]={0},f[222222]={0};

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n=0,m=0;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    if(m==1){
        sort(a+1,a+n+1,greater<long long>());
        printf("%lld",a[1]);
        return 0;
    }
    if(m==n){
        long long ans=a[1];
        for(long long i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%lld",ans);
        return 0;
    }
    if(m==2){
        long long ans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans){
                    ans=(a[i]&a[j]);
                }
            }
        }
        printf("%lld",ans);
        return 0;
    }

    long long ans=0,q=a[1];
    for(long long i=2;i<=n;i++){
        q&=a[i];
        if(q>ans){
            ans=q;
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
