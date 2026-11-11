#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int w[N],a[N][N],t[N][N],x,y;
int st[N][N];
int c,n,m,d,q,k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            st[a[i][j]][i]=1;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        if(st[x][i]==st[y][i]&&st[x][i]==1){
            cout<<w[x]+t[i][x]+t[i][y]+w[y];
            continue;
        }
    }
    return 0;
}
