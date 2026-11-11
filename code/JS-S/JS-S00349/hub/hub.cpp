//10
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,M=1e3+5;
int c,t,n,k;
vector<int>to[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            to[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        if(c==13||c==14){
            int m=(n-1)/2;
            if(k==1){
                cout<<ceil((m-1)*1.0/2)+1;
            }
            else if(k>1&&k<=m){
                cout<<ceil((ceil(m*1.0/2)-(k/2))*1.0/2)+1;
            }
            else if(k>m&&k<n){
                cout<<1<<'\n';
            }
            else if(k==n){
                cout<<0<<'\n';
            }
            continue;
        }

    }
    return 0;
}
