#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
typedef long long ll;
const int N=2000005;
ll x[N],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>x[i];
        }
            ll m=x[2]-x[1];
            if (m>d){
                cout<<0<<'\n';
                continue;
            }
            d/=m;
            d+=d-1;
            if (n>d)cout<<n-d<<'\n';
            else cout<<0<<'\n';
    }
    return 0;
}
