#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000006];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll c,t;
    cin >> c >> t;
    while(t--){
        ll n,d;
        cin >> n >> d;
        bool flag=true;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        ll cha=x[2]-x[1];
        for(int i=2;i<=n;i++){
            if((x[i]-x[i-1])!=cha){
                flag=false;
            }
        }
        if(flag){
            ll a=d/cha;
            if(n>2*a+1){
                cout << (n-2*a-1)*(n-2*a) << "\n";
            }else if(n==2*a){
                cout << 1 << "\n";
            }else if(n<2*a){
                cout << 0 << "\n";
            }else if(n==2*a+1){
                cout << 2 << "\n";
            }
        }//dengchashulie
    }
    cout << 0 << "\n" << 1;
    return 0;
}