#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],f[5009][5009],ans[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    //
    long long x=a[1]-a[2];
    bool flag=1;
    for(int i=1;i<n;i++){
        if(a[i]-a[i+1]!=x){
            flag=0;
        }
    }
    if(flag){
        x=abs(x);
        long long ansp=1,mp=m,xx=x;
        for(int i=1;i<n;i++){
            if(mp>=xx){
                mp-=x;
                xx=x+xx;
                ansp++;
            }else{
                break;
            }
        }
        printf("%lld",ansp);
        return 0;
    }

    //
    //printf("qqq");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
        f[i][i]=LLONG_MAX;
        ans[i]=1;
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        printf("%lld ",f[i][j]);
    //    }
    //    printf("\n");
    //}
    for(int i=1;i<=n;i++){
        sort(f[i]+1,f[i]+1+n);
        long long mm=m;
        for(int j=1;j<=n;j++){
            if(f[i][j]<0){
                continue;
            }
            if(f[i][j]<=mm){
                ans[i]++;
                mm-=f[i][j];
            }else{
                break;
            }
        }

    }
    long long re=0;
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        printf("%lld ",f[i][j]);
    //    }
    //    printf("\n");
    //}
    for(int i=1;i<=n;i++){
        re=max(re,ans[i]);
        //printf("%lld ",ans[i]);
    }
    printf("%lld",re);
    return 0;

}
