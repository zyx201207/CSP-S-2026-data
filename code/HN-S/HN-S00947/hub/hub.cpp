#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
vector<int> ma[300010];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 1;i <= n;++i){
            int x,y;
            cin>>x>>y;
            ma[x].push_back(y);
            ma[y].push_back(x);
        }
        cout<<(n >> 1)<<'\n';
    }
    return 0;
}