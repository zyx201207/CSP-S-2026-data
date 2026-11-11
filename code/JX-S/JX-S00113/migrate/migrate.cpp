#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=2e4+10;
ll c,t,n,d,a[N];
int f[M][M];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n-1;i++){
            for(int j=i+2;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(a[j]-a[k]<=d&&a[k]-a[i]<=d){
                        f[i][j]++;
                        cout<<i<<" "<<k<<" "<<j<<"\n";
                    } 
                }if(f[i][j]==2) ans++;
            }
        }cout<<ans<<"\n";
    }
    return 0;
}