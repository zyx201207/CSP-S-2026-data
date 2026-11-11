#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int ans=-1;
int a[N];
signed main(){        
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    int n,d,cnt;
    for(int i=1;i<=t;i++){
        scanf("%lld%lld",&n,&d);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[j]);
        }
        int dis=a[2]-a[1];
 //       printf("%lld",dis);
        if((2*dis)>d){
            ans=0;
        }
        if(d>(n*dis)){
            int b=n-3;
            if(b%2==1){
            ans=b-((b-1)/2);
            }
            else{
            ans=b/2;
            }
        }
        int cnt=(d/dis)+2;
        if(ans==-1){
             if(cnt%2==1){
                ans=cnt-((cnt-1)/2);
            }
            else{
                ans=cnt/2;
            }
        }
        printf("%lld\n",ans);
   }
    return 0;
}
