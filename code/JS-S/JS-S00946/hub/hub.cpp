#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+9;
int c;
ll t;
ll n,k;
vector<ll>mp;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            mp.push_back({u,v});
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
