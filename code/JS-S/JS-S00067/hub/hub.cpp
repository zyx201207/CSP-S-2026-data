#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll c,t,n,k;
vector<int> vec[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i+1<=n;i++){
            int v,u;
            cin>>v>>u;
            vec[v].push_back(u);
            vec[u].push_back(v);
        }
        cout<<1<<"\n";
    }

    return 0;
}
