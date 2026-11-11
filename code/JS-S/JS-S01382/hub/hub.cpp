#include<bits/stdc++.h>
#define elif else if
#define endl '\n'
using namespace std;
typedef long long ll;
ll n,k;

vector<ll>e[1000007];


int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,c;
    cin>>c;
    cin>>t;

    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);

        }

        cout<<(k+1)/2<<endl;
    }
    return 0;
}
