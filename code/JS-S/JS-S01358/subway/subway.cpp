#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,v,k[501],w[501],a[501][500001],t[501][500001];
int main(){
    srand(time(0));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int l=rand()%n+1,r=rand()%n+1;
        cout<<w[x]+w[y]+t[l][rand()%k[l]+1]+t[r][rand()%k[r]+1]<<"\n";
    }
    return 0;
}
