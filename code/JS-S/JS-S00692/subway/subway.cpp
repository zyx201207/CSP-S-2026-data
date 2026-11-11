#include<bits/stdc++.h>
using namespace std;
#define int long long
int tot,ver[2000005],head[1000005],nex[1000005],d[1005][1005],edge[2000005],w[1000005];
int t[2005][2005],a[2005][2005],m;
priority_queue<pair<int,int>> q;
void add(int x,int y,int z){
    ver[++tot]=y;
    edge[tot]=z;
    nex[tot]=head[x];
    head[x]=tot;
}
void floyd(){
    for(int i=1;i<=m;i++)
        d[i][i]=0;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}
void work(int x,int y){
    cout<<d[x][y]+w[x]+w[y]<<'\n';
}
void work2(int x,int y,int z){
    d[x][y]=z;
    d[y][x]=z;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(d,0x3f,sizeof(d));
    int c,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k*2;j++){
            if(j%2!=0)
                cin>>a[i][j/2+1];
            else
                cin>>t[i][j/2];
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                work2(a[i][j],a[i][l],t[i][j]+t[i][l]);
            }
        }
    }
    floyd();
    while(q--){
        int pp,qq;
        cin>>pp>>qq;
        work(pp,qq);
    }
    return 0;
}