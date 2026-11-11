#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,a[1000010];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,k,ans;
        cin>>n>>k;
        cin>>ans;
        for(int i=2;i<=n-1;i++){
            cin>>a[i];
            ans^=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
