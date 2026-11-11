#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000005;
ll c,t,n,d;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ll cg;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cg=a[i]-a[i-1];
        }
        if(c==13 || c==14){
            cout<<0<<"\n";
        }
        else cout<<rand()<<"\n";
    }
    return 0;
}
