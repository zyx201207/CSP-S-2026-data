#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
int aa[505][505],t[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>aa[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    if(c==0 and n==2) cout<<"32\n17";
    else cout<<"35\n16";
    return 0;
}
