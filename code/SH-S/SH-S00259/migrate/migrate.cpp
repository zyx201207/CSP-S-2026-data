#include<cstdio>
using namespace std;
int c,t,n,d;
int a[2000005];
int bk[2000005];
int fk[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--) {
        scanf("%d%d",&n,&d);
        long long ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        bk[1]=1;
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]>d) bk[i]=1;
            else if(i>=2&&a[i]-a[i-2]>d) bk[i]=bk[i-1]+1;
            else bk[i]=1;
        }
        fk[n]=1;
        for(int i=n-1;i>=1;i--){
            if(a[i+1]-a[i]>d) fk[i]=1;
            else if(i<=n-2&&a[i+2]-a[i]>d) fk[i]=fk[i+1]+1;
            else fk[i]=1;
        }
//        printf("%d%d%d%d",a[1],a[2],a[3],a[4]);
        for(int i=1;i<=n-3;i++){
            if(a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d&&
               a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d) ans+=bk[i]*fk[i+3];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
