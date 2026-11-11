#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int c,n,m,d,q;
int w[505],a[505][MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int pos;
            cin>>pos;
            cin>>a[i][pos];
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    return 0;
}
