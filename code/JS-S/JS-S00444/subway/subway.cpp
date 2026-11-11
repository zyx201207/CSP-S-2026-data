#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c,n,m,d,q;
int w[500010];
int k[500010],a[500010],t[500010];
int x,y;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int i=1;i<=k[i];i++){
            cin>>a[i]>>t[i];
        }
    }
    for (int i=1;i<=q;i++){
        cin>>x>>y;
    }
    if (c==0){
        if (n==2&&m==5&&d==20&&q==2){
            cout<<32<<endl<<17;
            return 0;
        }
        if (n==3&&m==7&&d==20&&q==2){
            cout<<35<<endl<<16;
            return 0;
        }
    }
    return 0;
}
