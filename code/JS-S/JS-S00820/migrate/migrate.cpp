#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,s[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d>>s[0];
        for(int i=1;i<n;i++){
            ll x;cin>>x;
            s[i]=x-s[i-1];
        }
        if(n<3)cout<<0<<endl;
            if(d<s[1]*2)cout<<0<<endl;
            else if(d>=s[1]*3){
                cout<<n-2<<endl;
            }
            else{
                cout<<n*2-5<<endl;
            }
    }
    return 0;
}
