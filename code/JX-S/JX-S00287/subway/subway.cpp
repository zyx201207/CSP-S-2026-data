#include<bits/stdc++.h>
using namespace std;
int w[505],kk[505][505],line[505][555],tim[555][505];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            if(i==j)kk[i][j]==0;
            else kk[i][j]==510000;
        }
    }
    int k;cin>>k;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>line[i][j]>>tim[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        int pos=2;
        for(int j=2;j<=k;j++){
                /*
            int u,v;
            if(pos==2){
                u=line[i][j];
                pos=(pos+1)%2;
            }
            else if(pos==1){
                cin>>u;
                swap(u,v);
                pos=(pos+1)%2;
            }
            else{
                cin>>v
            }*/
            kk[line[i][j]][line[i][j-1]]=min(kk[line[i][j]][line[i][j-1]],tim[i][j]);
            kk[line[i][j-1]][line[i][j]]=min(kk[line[i][j]][line[i][j-1]],tim[i][j]);
        }
    }

    for(int p=1;p<=n;p++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                kk[i][j]=min(kk[i][j],kk[i][p]+kk[p][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        cout<<kk[x][y]+w[x]+w[y]<<"\n";
    }
}
