#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
const int N=1e6+9;
int c,t,n,k;vector<int>g[N];
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    for(cin>>c>>t;t--;){
        cin>>n>>k;int A=n&1,m=n>>1;
        for(int u,v,i=1;i<n;i++){
            cin>>u>>v,g[u].eb(v),g[v].eb(u);
            if(!(i<=m&&u==i&&v==i+1||i>m&&u==i-m&&v==i+1))A=0;
        }
        if(A)cout<<(m-k+3)/4+1<<'\n';
        else{
            cout<<n/(k+1)<<'\n';
        }
    }
    return 0;
}