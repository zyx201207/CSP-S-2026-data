#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
long long c,T,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n>5000){
            long long u=x[2]-x[1];
            long long k=d/u;
            if(k==1){
                cout<<"0\n";
                continue;
            }
            long long ans=0;
            for(int i=1;i<=k-1;i++){
                if(n-i*2<1) break;
                ans+=n-i*2;
            }
            cout<<ans;
            continue;
        }
        long long dp1[n+9],dp2[n+9];
        x[n+1]=x[n]+1;x[0]=x[1]-1;
        for(int i=1;i<=n;i++){
            dp1[i]=-1;dp2[i]=n+1;
            if(x[n]-x[i]<d) {
                dp1[i]=-1;
            }
            else {
                for(int j=i+1;j<n+2;j++) {
                    if(x[j]-x[i]>d){
                        dp1[i]=j-1;
                        break;
                    }
                }
            }
            if(x[i]-x[1]<d) {
                dp2[i]=n+1;
            }else {
                for(int j=i-1;j>=0;j--){
                    if(x[i]-x[j]>d){
                        dp2[i]=j+1;
                        break;
                    }
                }
            }
        }
        /*
        for(int i=1;i<=n;i++) cout<<dp1[i]<<" ";cout<<"\n";
        for(int i=1;i<=n;i++) cout<<dp2[i]<<" ";cout<<"\n";
        //*/
        long long ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((dp1[i]==i&&dp1[j]==j)||(dp2[i]==i&&dp2[j]==j)) continue;
                if(x[j]-x[i]<=d) continue;
                if((dp1[i]>dp2[j])&&(dp1[i]-dp2[j]<d)) {
                    bool ok=1;
                    for(int k=dp2[j]+1;k<dp1[i];k++){
                        if(x[k]-x[i]<=d&&x[j]-x[k]<=d){
                            ok=0;
                            break;
                        }
                    }
                    if(ok) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
