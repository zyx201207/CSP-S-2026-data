#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,ans=0,num;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){cin>>x[i];}
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                int tt=x[j]-x[i];
                if(tt%d==1){ans++;}
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
