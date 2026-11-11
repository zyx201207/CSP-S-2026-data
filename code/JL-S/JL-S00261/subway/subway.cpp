#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,int>
using namespace std;
const int N=1005;
const ll inf=LLONG_MAX;
const int mxN=5e5+5;
ll dis[N][N];
int w[mxN];
struct st{
    int id;
    ll w;
}a[mxN];
int main(){
    freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c<=8){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++) dis[i][j]=inf;
            dis[i][i]=0;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
                cin>>a[j].id>>a[j].w;
        }
            for(int j=1;j<=k;j++){
                for(int l=j+1;l<=k;l++){
                    int u=a[j].id,v=a[l].id;
                    dis[u][v]=min(dis[u][v],(ll)a[j].w+(ll)a[l].w);
                }
            }
    }
        //flord
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    if(i==j||i==k||j==k) continue;
                    if(dis[i][k]==inf||dis[k][j]==inf) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        while(q--){
            int a,b;
            cin>>a>>b;
            cout<<min(dis[a][b],dis[b][a])+(ll)w[a]+(ll)w[b]<<'\n';
        }
    return 0;
}
