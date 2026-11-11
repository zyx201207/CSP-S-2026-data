#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll c,n,m,q,d;

ll w[500005];
ll a[505][505];
ll t[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int i=1;i<=k;++i){
            cin>>a[i][k]>>t[i][k];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<"\n";
    }
    return 0;
}
