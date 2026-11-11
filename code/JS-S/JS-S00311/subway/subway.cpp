#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,w[N],a[N],t[N],k[N],x[N],y[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    if(n==1||d==1){
        for(int i=1;i<=q;i++){
           cout<<w[x[i]]+w[y[i]]+t[x[i]]+t[y[i]];
        }
    }
    return 0;
}

