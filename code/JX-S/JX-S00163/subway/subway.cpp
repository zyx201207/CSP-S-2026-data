#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500];
int k;
int a[500][500];
int t[500][500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int x,y;
        cout<<w[x]+t[1][x]+t[1][y]+w[y];
    }
    return 0;
}
