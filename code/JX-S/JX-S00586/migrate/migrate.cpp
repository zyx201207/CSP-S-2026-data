#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define ll long long
ll c,t,n,d,x[N],a,b;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        a=x[2]-x[1];
        if(a>d||d<2*a){
            cout<<0<<endl;
            return 0;
        }
        b=d/a*a;
        cout<<n-2*b/a+1<<endl;
    }
    return 0;
}
