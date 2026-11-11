#include <iostream>
using namespace std;
long long c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i = 1;i<=t;i++){
        long long n,d,a[1000005];
        cin>>n>>d;
        for(int i = 1;i<=n;i++) cin>>a[i];
        if(d*2==a[n]-a[1]+1) cout<<1;
        else cout<<(a[n]-a[1]+d-2)/d;
    }
    return 0;
}
