#include<bits/stdc++.h>
#define sum12 w[u]+w[v]+t[1][u]+t[1][t12]+t[2][t12]+t[2][v]
#define sum21 w[u]+w[v]+t[2][u]+t[1][t12]+t[2][t12]+t[1][v]
#define sum13 w[u]+w[v]+t[1][u]+t[1][t13]+t[3][t13]+t[3][v]
#define sum31 w[u]+w[v]+t[3][u]+t[1][t12]+t[3][t13]+t[1][v]
#define sum23 w[u]+w[v]+t[2][u]+t[2][t23]+t[3][t23]+t[3][v]
#define sum32 w[u]+w[v]+t[3][u]+t[2][t23]+t[3][t23]+t[2][v]
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],a[5][N],t[5][N];
int k[N],f1[N],f2[N],f3[N],t12,t23,t13;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=N-3;j++)
            t[i][j]=-1,f1[j]=f2[j]=f3[j]=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            if(i==1)f1[a[i][j]]=1;
            if(i==2){
                f2[a[i][j]]=1;
                if(f1[a[i][j]])t12=a[i][j];
            }
            if(i==3){
                f3[a[i][j]]=1;
                if(f1[a[i][j]])t13=a[i][j];
                if(f2[a[i][j]])t23=a[i][j];
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(n==1){
            cout<<w[u]+w[v]+t[1][u]+t[1][v]<<"\n";
        }else if(n==2){
            if(f1[u]&&f1[v]){
                cout<<w[u]+w[v]+t[1][u]+t[1][v]<<"\n";
            }else if(f2[u]&&f2[v]){
                cout<<w[u]+w[v]+t[2][u]+t[2][v]<<"\n";
            }else if(f1[u]&&f2[v]){
                cout<<w[u]+w[v]+t[1][u]+t[1][t12]+t[2][t12]+t[2][v]<<"\n";
            }else{
                cout<<w[u]+w[v]+t[2][u]+t[1][t12]+t[2][t12]+t[1][v]<<"\n";
            }
        }else{
            if(f1[u]&&f1[v]){
                cout<<w[u]+w[v]+t[1][u]+t[1][v]<<"\n";
            }else if(f2[u]&&f2[v]){
                cout<<w[u]+w[v]+t[2][u]+t[2][v]<<"\n";
            }else if(f3[u]&&f3[v]){
                cout<<w[u]+w[v]+t[3][u]+t[3][v]<<"\n";
            }else if(f1[u]&&f2[u]&&f3[v]){
                cout<<min(sum13,sum23)<<"\n";
            }else if(f1[u]&&f3[u]&&f2[v]){
                cout<<min(sum12,sum32)<<"\n";
            }else if(f3[u]&&f2[u]&&f1[v]){
                cout<<min(sum21,sum31)<<"\n";
            }else if(f3[u]&&f2[v]&&f1[v]){
                cout<<min(sum32,sum31)<<"\n";
            }else if(f2[u]&&f3[v]&&f1[v]){
                cout<<min(sum31,sum21)<<"\n";
            }else if(f1[u]&&f2[v]&&f3[v]){
                cout<<min(sum12,sum13)<<"\n";
            }else if(f1[u]&&f2[v]){
                cout<<min(sum12,sum13+sum32-2*w[3])<<"\n";
            }else if(f2[u]&&f1[v]){
                cout<<min(sum21,sum23+sum31-2*w[3])<<"\n";
            }else if(f1[u]&&f3[v]){
                cout<<min(sum13,sum12+sum23-2*w[2])<<"\n";
            }else if(f3[u]&&f1[v]){
                cout<<min(sum31,sum32+sum21-2*w[2])<<"\n";
            }else if(f2[u]&&f3[v]){
                cout<<min(sum23,sum21+sum13-2*w[1])<<"\n";
            }else{
                cout<<min(sum32,sum31+sum12-2*w[1])<<"\n";
            }
        }
    }

    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
