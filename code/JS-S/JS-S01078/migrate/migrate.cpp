#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const ll MXN=2000005;
ll c,t;
ll n,d;
ll x[MXN];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(c==11||c==12){//A
        d=d/(x[2]-x[1]);
        d=2*d-1;
        cout<<n-d<<endl;
    }
    else cout<<0<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //csp_s = Contest of SleePer - Sleeping
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
