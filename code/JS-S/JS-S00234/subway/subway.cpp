#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    long long a[500][500005],t[500][500005];
    long long w[500005];
    long long x[100005],y[100005];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){
        int cnt=w[x[i]]+w[y[i]]+1;
        cout<<cnt<<endl;
    }
    return 0;
}
