#include<bits/stdc++.h>
#define N 2000005
#define int long long
using namespace std;
int C,T,n,d,x[N],f[N],num[N],ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&C,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);ans=0;
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++)f[j]=3e18,num[j]=0;
            num[i]=1,f[i]=0;
            for(int j=i+1;j<=n;j++){
                int mn=3e18,ap=0;
                for(int k=j-1;k>=i;k--){
                    if(x[j]-x[k]>d)break;
                    if(f[k]<mn)mn=f[k],ap=num[k];
                    else if(f[k]==mn)ap+=num[k];
                }if(mn==3e18)break;
                f[j]=mn+1,num[j]=ap;
                if(num[j]==2)ans++;
            }
            /*cout<<i<<": \n";
            for(int j=i;j<=n;j++)cout<<num[j]<<' ';
            cout<<endl;*/
        }printf("%lld\n",ans);
    }
}
