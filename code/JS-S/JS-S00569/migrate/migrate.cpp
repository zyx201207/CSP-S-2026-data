#include <bits/stdc++.h>
using namespace std;
//bao li chu qi ji!!!
int n,m,i,j,k,l,c,t,a[1000009],x,y,f[5009][5009],b[5009][5009],ans;
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        for(i=1;i<=n;i++)cin>>a[i];
        for(i=1;i<=n;i++)for(j=1;j<=n;j++){
                f[i][j]=INT_MAX;
                b[i][j]=0;
        }
        for(i=1;i<=n;i++)f[i][i]=1;
        for(i=1;i<=n;i++){
            for(j=i-1;j>=1&&a[i]-a[j]<=m;j--){
                for(k=1;k<=j;k++){
                    f[i][k]=min(f[i][k],f[j][k]);
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=i-1;j>=1&&a[i]-a[j]<=m;j--){
                for(k=1;k<=j;k++){
                    if(f[j][k]==f[i][k])b[i][k]++;
                }
            }
            for(j=1;j<=i;j++)if(b[i][k]==2)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
