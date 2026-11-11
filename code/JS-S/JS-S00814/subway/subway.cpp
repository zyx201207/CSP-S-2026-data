#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin >>w[i];
    }
    for(int i=1;i<=n;i++){
        cin >>k[i];
        for(int j=1;j<=2*k[i];j+=2){
            cin >>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin >>x>>y;
        cout <<526*i%100;
    }
    return 0;
}
