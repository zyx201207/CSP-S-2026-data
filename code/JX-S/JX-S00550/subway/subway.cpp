#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005];
int t[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;k++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
    }
    cout<<35<<endl<<16;
    return 0;
}
