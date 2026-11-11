#include<bits/stdc++.h>
using namespace std;

//#define int long long

const long long INF=5e12+100;

struct edge{
    int u,v,w;
};

int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005];
int station[500005][25],pssroad[500005];

long long dis[505][505];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            dis[i][j]=INF;
            if(i==j) dis[i][j]=0;
        }
    }

    cin>>c>>n>>m>>d>>q;
    int tt;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>tt;
            station[a[i][j]][++pssroad[a[i][j]]]=i;
            t[i][a[i][j]]=tt;
        }
    }

    for(int i=1;i<=m;i++){
        if(pssroad[i]>=2){
            for(int j=1;j<=pssroad[i];j++){
                for(int k=j+1;k<=pssroad[i];k++){
                    //station[i][j] station[i][k]
                    dis[station[i][j]][station[i][k]]=dis[station[i][k]][station[i][j]]=t[station[i][j]][i]+t[station[i][k]][i];
                }
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(k==i || k==j) continue;
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    int x,y;
    while(q--){
        cin>>x>>y;
        long long ans=1e18;
        for(int i=1;i<=pssroad[x];i++){
            long long len=0;
            for(int j=1;j<=pssroad[y];j++){
                len=w[x]+w[y]+dis[station[x][i]][station[y][j]]+t[station[x][i]][x]+t[station[y][j]][y];
                ans=min(ans,len);
            }
        }
        cout<<ans<<'\n';
    }

    return 0;

}
