#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n;
ll a[N];
ll d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        bool typeA=true;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=3&&a[i]-a[i-1]!=a[2]-a[1])typeA=false;
        }
        if(typeA){
            ll k=a[2]-a[1];
            d/=k;
            if(d<2){
                cout<<0;
                if(t!=0)cout<<'\n';
            }else{
                cout<<max(0ll,(a[n]-a[1])/k-2);
                if(t!=0)cout<<'\n';
            }
        }else{
            cout<<0;
            if(t!=0)cout<<'\n';
        }
    }
    return 0;
}
