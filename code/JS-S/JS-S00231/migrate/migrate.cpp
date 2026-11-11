#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d;
long long x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        long long cc=x[2]-x[1];
        d=d/cc;long long o=0;
        cout<<(n-d)/d*(d-1)+min(o,n%d-1)<<"\n";
    }
    return 0;
}
