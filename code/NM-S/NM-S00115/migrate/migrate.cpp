#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+10;
int c,t,n;
unsigned long long d;
long long x[MAXN];
unsigned main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(d<2*(x[2]-x[1])) cout<<0<<"\n";
        else if(n<=3) cout<<0<<"\n";
        else if((d/(x[2]-x[1])%2==0)){
            int cnt=n-n/2;
            int ans=0;
            for(int j=1;j<=cnt-1;j++){
                ans+=j;
            }
            cout<<ans<<"\n";
        }
        else if((d/(x[2]-x[1])%2==1)){
            int cnt=n/2;
            int ans=0;
            for(int j=1;j<=cnt-1;j++){
                ans+=j;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
