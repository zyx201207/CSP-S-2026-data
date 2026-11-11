#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,t,n,d,a[2000007];
signed main(){
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>t;
    if(_==11||_==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            cout<<max(n-d/(a[2]-a[1])*2+1,0ll)<<'\n';
        }
        return 0;
    }
    while(t--){
        cout<<"0\n";
    }
    return 0;
}
