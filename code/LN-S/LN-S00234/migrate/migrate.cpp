#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long c,t,a[5005],f[5005][5005],ans[5005][5005],sum,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(f,0x7f,sizeof f);
        memset(ans,0,sizeof ans);
        sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            f[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[j]-a[k]>d) break;
                    if(f[i][j]==f[i][k]+1){
                        ans[i][j]++;
                    }
                    if(f[i][j]>f[i][k]+1){
                        f[i][j]=f[i][k]+1;
                        ans[i][j]=1;
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans[i][j]==2) sum++;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
