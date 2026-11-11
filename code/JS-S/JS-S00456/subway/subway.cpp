#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,n,m,d,q,x,y,w[N],k[N],a[N][25],t[N][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<w[x]+(y-x)*2*t[1][1]+w[y]<<'\n';
    }
    return 0;
}
