#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
vector<int> e[N];
int c,n,m,d,q,w[N],f[N][N],k[N],a[N][N],t[N][N];
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        f[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            f[a[i][j]][a[i][j+1]]=t[i][j];
            f[a[i][j+1]][a[i][j]]=t[i][j];
        }
    }
    for(int k=1;k<=1e3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+f[x][y]+w[y]<<endl;
    }
    return 0;
}

