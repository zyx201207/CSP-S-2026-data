#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,c;
ll n,m;
ll a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll ls=m*2-1;
        cout<<n-ls<<'\n';
    }
    return 0;
}
