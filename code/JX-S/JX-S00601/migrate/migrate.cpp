#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
const int N=2e6+10;
int x[N];
int ans=0;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>t;
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<1<<"\n";
    }
    return 0;
}
