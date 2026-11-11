#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=300,N=50;
int w[M],a[N],t[M][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)cin>>w[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            cin>>a[j];
            cin>>t[a[j]][i];
        }
    }

    return 0;
}
