#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+10;
ll c,t,n,d,x[MAXN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                if(d/(abs(x[j-1]-x[i]))>=1&&d/(abs(x[i+1]-x[j]))>=1&&d/(abs(x[i]-x[j]))==0){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
