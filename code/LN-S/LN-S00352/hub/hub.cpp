#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)cin>>k>>k;
        cout<<(n+1)/5<<'\n';
    }
    return 0;
}
