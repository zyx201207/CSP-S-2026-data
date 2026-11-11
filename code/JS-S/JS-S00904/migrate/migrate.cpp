#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[5006][5006];
int a[200006];
int n,m;
int sum[5006][5006];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i>=k||j<=k) continue;
                // printf("i:%d k:%d j:%d +:%d d:%d\n",i,k,j,d[i][k]+d[k][j],d[i][j]);
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    sum[i][j]=1;
                }
                else if(d[i][k]+d[k][j]==d[i][j]){
                    sum[i][j]++;
                }
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=m) d[i][j]=1;
                else d[i][j]=1ll*0xffffffffffffff;
            }
        }
        floyd();
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                // printf("i:%lld j:%lld d:%lld\n",i,j,sum[i][j]);
                if(sum[i][j]==2){
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
                sum[i][j]=0;
                d[i][j]=0;
            }
        }
        cout<<ans<<endl;
    }
}