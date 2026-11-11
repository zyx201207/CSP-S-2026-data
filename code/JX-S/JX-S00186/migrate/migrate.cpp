#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                long long s=0;
                for(int k=i;k<=j;k++){
                    if(abs(x[k]-x[i])<=d && abs(x[j]-x[k])<=d){
                        s++;
                        //cout<<i<<k<<j<<"\n";
                    }
                }
                if(s==2) ans++;
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
