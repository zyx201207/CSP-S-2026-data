#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,t,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        ll D=x[2]-x[1];
        ll m=d/D;
        if(m==1) {
            cout<<0<<endl;
            continue;
        }
        cout<<max(0ll,n+1-2*m)<<endl;
    }
    return 0;
}
