#include <bits/stdc++.h>
using namespace std;
long long a[10000006],dp[10000006],luxian[10000006];
//juli:dp[i]=(keda)min(dp[j])+1
//luxian:zuiduankedadezuiduanluxianxiangjia
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        long long sum=0;
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long mn=1e16+6;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                dp[i]=0;
                luxian[i]=0;
            }
            dp[k]=1;
            luxian[k]=1;
            for(int i=k+1;i<=n;i++){
                for(int j=k;j<i;j++){
                    if(a[j]>=a[i]) break;
                    if(a[j]<a[i]-d||a[j]<a[k]) continue;
                    if(dp[j]<mn) mn=dp[j];
                }
                dp[i]=mn+1;
                for(int j=k;j<i;j++){
                    if(a[j]>=a[i]) break;
                    if(a[j]<a[i]-d) continue;
                    if(dp[j]==mn) luxian[i]+=luxian[j];
                }
                mn=1e16+6;
                if(luxian[i]==2) sum++;
            }
        }
        cout<<sum<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
