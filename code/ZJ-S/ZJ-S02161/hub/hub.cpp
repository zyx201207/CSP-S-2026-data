#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++i)
const ll N=500+10;
const ll M=5e5+10;

ll c,t,n,k;
vector<ll> g[N];

void solve1(){
    
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        rep(i,1,n) g[i].clear();
        for(int x,y,i=1;i<n;++i){
            cin>>x>>y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if(c<=10) solve1();
    }
    return 0;
}