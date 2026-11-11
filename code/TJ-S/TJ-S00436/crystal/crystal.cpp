#include<bits/stdc++.h>
using namespace std;

long long a[555555]={0},c[555555]={0};

int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);

    long long n=0,m=0;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);

    if(n<=5000){
        for(long long i=2;i<=n;i++){
            c[i]=a[i]-a[i-1];
        }

        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long ax=111111111111,f=0;
            for(long long j=2;j<=n;j++){
                if(c[j]<ax && c[j]!=0){
                    ax=c[j];
                    f=j;
                }
            }
            if(m>=ax){
                m-=ax;
                if(a[f-1]!=a[f]){
                    ans++;
                }
                a[f-1]=a[f];
                c[f]=0;
            }
            else{
                break;
            }
        }
        printf("%lld",ans);
        return 0;
    }

    long long t=a[2]-a[1];
    long long ans=0;
    while(true){
        m-=t;
        if(m<0){
            break;
        }
        t*=2;
        ans++;
    }
    ans=min(ans+1,n);
    printf("%lld\n",ans);

    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
