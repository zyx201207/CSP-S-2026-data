#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((x[j]-x[i])%d!=1&&(x[j]-x[i])/d>0){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
