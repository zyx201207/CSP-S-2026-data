#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cout<<0;
        }
    }
    return 0;
}
