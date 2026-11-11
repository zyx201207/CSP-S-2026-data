#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
#define int long long
int x[N],c,t,n,d,ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        for(int i=1;i<=n;i++){
            int k=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            if(k-i<2||k==n)continue;
            int k1=upper_bound(x+1,x+n+1,x[k-2]+d)-x;
            int k2=upper_bound(x+1,x+n+1,x[k-1]+d)-x-1;
            if(k1>k2)continue;
            int pos=i,num1=1,num2=1;
            while(pos>1){
                int k3=lower_bound(x+1,x+n+1,x[pos]-d)-x;
                int k4=lower_bound(x+1,x+n+1,x[pos+1]-d)-x-1;
                if(k3>k4)break;
                num1+=(k4-k3+1);
                pos=k3;
            }
            //cout<<i<<" "<<k<<" "<<k1<<" "<<k2<<endl;
            for(int j=k1;j<=k2;j++){
                pos=j;num2=1;
                while(pos<n){
                    int k3=upper_bound(x+1,x+n+1,x[pos]+d)-x-1;
                    int k4=upper_bound(x+1,x+n+1,x[pos-1]+d)-x;
                    //cout<<i<<" "<<k3<<" "<<k4<<"fjhsdbfsd"<<endl;
                    if(k3<k4)break;
                    num2+=(k3-k4+1);
                    pos=k3;
                }
                //cout<<j<<" "<<num1<<" "<<num2<<endl;
                ans+=num1*num2;
            }
            //cout<<i<<" "<<num1<<" "<<num2<<endl;
        }
        cout<<ans<<endl;
    }
}