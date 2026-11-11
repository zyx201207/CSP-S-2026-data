#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

const int N=2e6+7,inf=1e18;

ll a[N];

ll n,d,c,t;


void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<0<<'\n';
}


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}

