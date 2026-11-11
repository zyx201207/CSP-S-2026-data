#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
        int ans = 0;
        for(int i = 1;i<=n-d-1;i++){
            for(int j = i+d+1;j<=n;j++){
                int cnt = 0;
                for(int k = i+1;k<=j-1;k++){
                    if(x[k]-x[i]<=d&&x[j]-x[k]<=d){
                        cnt++;
                    }
                }
                if(cnt == 2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
