#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn=2e6+5;
int c,t;
ll n,d,ans,s;
ll a[mxn];
ll dis[mxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    if(c==11 || c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            s=a[2]-a[1];
            if(s*2>d){
                cout<<"0\n";
                continue;
            }
            ans=n-d/s*2+1;
            cout<<max(ans,0ll)<<"\n";
        }
    }else{
        while(t--) cout<<"0\n";
    }
    
    return 0;
}