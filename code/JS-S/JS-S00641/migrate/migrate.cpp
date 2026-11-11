#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int aa[2000010];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>aa[i];
        cout<<n/2<<endl;
    }
    return 0;
}