#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t;
int n,k;
vector<int> G[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int ans;
        for(int i=1;i<=n-1;i++){
            int x,y;
            cin>>x>>y;
            ans=int(ceil(sin(x+cos(y))))%(x+y);
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}
