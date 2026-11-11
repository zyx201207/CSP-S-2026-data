#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[10005][10005],t[10005][10005],k[50005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
    }//完全没头绪。。。
    return 0;
}
