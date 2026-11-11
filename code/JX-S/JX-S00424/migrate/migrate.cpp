#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2100000],fr[2100000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.our","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(n<=3){
            printf("0\n");
            continue;
        }
        long long cnt=0,ans=0,f=0,lst=0,p=0,k=1;
        bool f1=0;
        for(int i=1;i<=n-3;i++){
            cnt++;
            if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d){
                ans++;
                cnt--;
                if(!f1){
                    ans=ans+cnt;
                    f1=1;
                    p=i;
                }else{
                    if(p+1==i){
                        p=i;
                        k++;
                    }else if(p+3==i){
                        ans=ans+2;
                        //k++;
                        p=i;
                    }else{
                        ans=ans+k*2*(cnt)+1;
                        k=1;
                    }
                }
                cnt=0;
            }
            if(a[i+1]-a[i]>d){
                ans=ans+f1*(cnt-3);
                cnt=0;
                f1=0;
            }
        }
        for(int i=n-2;i<=n-1;i++){
            cnt++;
            if(a[i+1]-a[i]>d){
                ans=ans+k*f1*(cnt-3);
                cnt=0;
                f1=0;
            }
        }
        cnt++;
        if(n-p>cnt){
            ans=ans+f1*(cnt-3);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
