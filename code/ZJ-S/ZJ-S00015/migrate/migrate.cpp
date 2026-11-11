#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        int n,d,ans=0,p[1<<21],l[1<<21],r[1<<21];
        cin>>n>>d;
        p[0]=LONG_LONG_MIN,p[n+1]=LONG_LONG_MAX,l[n+1]=r[n+1]=n+1,l[0]=r[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&p[i]);
        }
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(p,p+i,p[i]-d)-p;
            r[i]=upper_bound(p+i,p+n+2,p[i]+d)-p-1;
        }
        for(int i=1;i<n;i++){
            if((r[i]-i-2>0)&&(r[i]==r[i+1])){
                ans-=r[i]-i-2;
            }
        }
        for(int i=2;i<n-1;i++){
            int lcnt=l[i+2]-l[i+1];
            int rcnt=r[i]-i-1;
            ans+=max(0ll,lcnt*rcnt);
        }
        cout<<ans<<"\n";
    }
    return 0;
}