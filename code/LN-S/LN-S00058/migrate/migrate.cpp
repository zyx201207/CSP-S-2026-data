#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int cc,T,n,d,a[N];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cc>>T;
    while(T--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++) cin>>a[i];
        int c = a[2]-a[1];
        if(c*(2*d-1)>n) cout<<0<<'\n';
        else cout<<n-c*(2*d-1)<<'\n';
    }
    return 0;
}
