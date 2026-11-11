#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long a[N];
long long f[4][N];
int n,m,v[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i&1][j]=f[i-1&1][j];
            f[i&1][j]=max((f[i-1&1][j-1]&a[i]),f[i-1&1][j]);
        }
    }
    cout<<f[n&1][m];
    return 0;
}
