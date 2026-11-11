#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int w[2000005];
int f[5000][5000];
int main(){
    auto fcin=ifstream("subway.in");
    auto fcout=ofstream("subway.out");
    int c,q,d;
    fcin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        fcin>>w[i];
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++){
            int k;
            fcin>>k;

        while(k--){

            int a,t;
            fcin>>a>>t;
            f[a][i+m]=t;

            f[i+m][a]=t;
        }
    }
    for(int k=1;k<=n+m;k++){
        for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
    }
    }
    }
    while(q--){
        int x,y;
        fcin>>x>>y;
        fcout<<w[x]+w[y]+f[x][y]<<"\n";
    }
    return 0;
}
