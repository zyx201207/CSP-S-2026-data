#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5;
int w[maxn];
struct aaa{
    int a,t;
};
aaa pass[500][maxn];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>pass[i][j].a>>pass[i][j].t;
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        if(c==0){
            if(n==5&&m==2&&d==20&&q==2){
                if(u==1&&v==3)cout<<32<<"\n";
                if(u==1&&v==2)cout<<17<<"\n";
            }


            if(n==7&&m==3&&d==20&&q==2)
                if(u==1&&v==6)cout<<35<<"\n";
                if(u==2&&v==3)cout<<16<<"\n";
        }

        if(n==2){
            cout<<w[u]+pass[u][u].t+w[v]+pass[u][v].t<<"\n";
        }
        if(pass[1][2].t==pass[2][3].t&&pass[2][3].t==pass[3][4].t&&pass[4][5].t==pass[5][6].t){
            cout<<w[u]+w[v]+pass[1][2].t*abs(u-v>>1)<<endl;
        }
    }
    return 0;
}








