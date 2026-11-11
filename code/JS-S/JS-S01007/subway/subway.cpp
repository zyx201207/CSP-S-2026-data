#include<bits/stdc++.h>
using namespace std;
//CCF had no
//horse and ax
long long c,n,m,d,p,w[500005],k[500005];
long long a[505][500005],t[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cout<<(c+n+m)%q<<endl;
    }
    return 0;
}
