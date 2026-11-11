#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[510],dist[510][510];

/*struct edge{
    int ed,v;
};*/

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            dist[i][j]=1000000010;
        }
    }
    for(int i=1;i<=500;i++){
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            int k,sum=0,u,v;
            int a;
            cin>>k;
            for(int i=1;i<=2*k;i++){
                cin>>a;
                if(i==1)u=a;
                if(i==3)v=a;
                if(i==2||i==4)sum+=a;
            }
            if(k==2)dist[u][v]=min(dist[u][v],sum),dist[v][u]=min(dist[v][u],sum);
        }
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dist[x][y]+w[x]+w[y]<<endl;
        }
    }else{
        int extra=0;
        for(int i=1;i<=n;i++){
            int k;
            int a;
            cin>>k;
            extra++;
            int node=extra+m;
            for(int i=1;i<=k;i++){
                int a,b;
                cin>>a>>b;
                dist[a][node]=b,dist[node][a]=b;
            }
        }
        for(int k=1;k<=m+extra;k++){
            for(int i=1;i<=m+extra;i++){
                for(int j=1;j<=m+extra;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<dist[x][y]+w[x]+w[y]<<endl;
        }
    }
    return 0;
}
