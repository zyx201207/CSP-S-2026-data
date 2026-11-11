#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d;
const int N=5000;
ll x[N];
int f[N][N];
int o[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll ans = 0;
        cin>>n>>d;
        if(c<=10){
            memset(f,0x3f3f3f3f,sizeof f);
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if(x[j]-x[i]<=d)f[i][j] = 1;
                }
            }
            for(int k=2;k<=n;k++){
                for(int i=1;i+k<=n;i++){
                    for(int j=k-1;j>=1;j--){
                       f[i][j] = min(f[i][i+k]+f[i+k][j]);
                    }
                }
            }
        }
    }
}
