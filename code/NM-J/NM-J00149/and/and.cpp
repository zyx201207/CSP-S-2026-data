#include<bits/stdc++.h>
using namespace std;

bool fun(int a1,int a2){
    return a1>a2;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n=0,m=0;
    scanf("%lld%lld",&n,&m);
    long long a[200005]={};
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,fun);
    if(m==1){
        printf("%lld",a[1]);
    }else if(m==2){
        long long ans=0,sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=a[i]&a[j];
                if(sum>ans){
                    ans=sum;
                }
            }
        }
        printf("%lld",ans);
    }else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%lld",ans);
    }
    return 0;
}
