#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
void slv1(){
    while(t--){
        cin>>n>>k;
        int m=n/2+1;
        if(k>=m-1) cout<<"1\n";
        else {
            int ans=(m-k)/4+1;
            if((m-k)%4==2 or (m-k)%4==3) ++ans;
            cout<<ans<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    slv1();
    return 0;
}
