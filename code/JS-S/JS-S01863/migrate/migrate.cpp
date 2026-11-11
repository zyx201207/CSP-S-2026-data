#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            int u=a[2]-a[1];
            if(u>d||d<2*u) cout<<"0\n";
            else cout<<max(0LL,n-2*(d/u)+1)<<"\n";
        }
    }
    return 0;
}
