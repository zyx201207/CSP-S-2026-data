#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MANX MAXN
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
namespace ylf{ void cat(); }

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T=1;
    cin>>c>>T;
    while(T--) ylf::cat();
    return 0;
}

namespace ylf{
    void cat(){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        cout<<(n-2*k+9)/8;
    }
}