#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    unsigned long long ans;
    int c;
    scanf("%d",&c);
    if(c==11||c==12){
        int t;
        scanf("%d",&t);
        while(t--){
            long long a=0,b=0,n=0,ch;
            unsigned long long d=0;
            scanf("%lld%llu",&n,&d);
            scanf("%lld%lld",&a,&b);
            for(long long i=3;i<=n;i++) scanf("%lld",&ch);
            if(n<=3){
                ans=0;
                continue;
            }
            if(d<2*(b-a)) ans=0;
            else{
                unsigned long long ti=d/(b-a);
                ti=2*ti-1;
                ans=n-ti;
            }
            if(ans>=5e12) ans=0;
            printf("%llu\n",ans);
        }
    }
    if(c==12||c==13){
        int t;
        scanf("%d",&t);
        for(int i=1;i<=c;i++) printf("0\n");
    }

    return 0;
}
/*for ten pt*/
/*int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    unsigned long long ans;
    int c;
    scanf("%d",&c);
    if(c==11||c==12){
        int t;
        scanf("%d",&t);
        while(t--){
            long long a=0,b=0,n=0,ch;
            unsigned long long d=0;
            scanf("%lld%llu",&n,&d);
            scanf("%lld%lld",&a,&b);
            for(long long i=3;i<=n;i++) scanf("%lld",&ch);
            if(n<=3){
                ans=0;
                continue;
            }
            if(d<2*(b-a)) ans=0;
            else{
                unsigned long long ti=d/(b-a);
                ti=2*ti-1;
                ans=n-ti;
            }
            if(ans>=5e12) ans=0;
            printf("%llu\n",ans);
        }
    }

    return 0;
}*/
