#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],t,point[500005][505],a[500005][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[i][j]>>t;
                int x=a[i][j];
                point[x][i]=1;
            }
        }

        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            int op=0;
            for(int k=1;k<=n;k++){
                if(point[x][k]&&point[y][k]){
                    cout<<w[x]+w[y]+t*2<<endl;
                    op=1;
                }
            }
            if(!op){
                cout<<n*2*t+w[x]+w[y]<<endl;
            }
        }
    return 0;
}
