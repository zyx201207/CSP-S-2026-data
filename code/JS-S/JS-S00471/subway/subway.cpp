#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+10,INF=1e9+10;

int n,m,q;
int w[N],dis[N][N];
int a[N][M],t[N][M];

int main(){ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    {int c,d;
        cin>>c>>n>>m>>d>>q;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            for(int e=1;e<i;e++){
                for(int r=1;r<=k;r++){
                    dis[a[e][r]][a[i][j]]=t[e][r]+a[i][j];
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<'\n';
    }
    return 0;
}
//qiao wan cai fa xian bu shi Floyd ban zi)
//bu guan le , tou yun
//pian wan bie de bu fen fen zai lai xiang ba

//? n zen me bu shi zhan dian shu
//wu qu bu zao shuo

//he zhe On^3 shi Om^3=1.235e12 shi ba
//bai

//you bu fen fen da ma

/*#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+10,INF=1e9+10;

int n,m,q;bool o;
bool f[1005][1005];
int w[N],dis[N][N];
int a[N][M],t[N][M];
vector<int>son[1005];
bool v[1005];

int dfs(int x,int cnt,int v){
    int ans=INF;
    v[x]=1;
    for(auto c:son[x]){
        if(v[c])continue;
        if(c==v){
            ans=min(ans,cnt);
        }
        dfs(c,xnt+)

    }
    return ans;
}

int main(){ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    {int c,d;
        cin>>c>>n>>m>>d>>q;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        if(k==2){
            int u,wu,v,wv;
            cin>>u>>wu>>v>>wv;
            a[i][1]=u;t[i][1]=wu;
            a[i][2]=v;t[i][2]=wv;
            dis[i][u]=wu,dis[i][v]=wv;
            son[u].push_back(v);
            son[v].push_back(u);
        }
        else{
            if(o)o=0;
            for(int j=1;j<=k;j++){
                cin>>a[i][j]>>t[i][j];
                for(int e=1;e<i;e++){
                    for(int r=1;r<=k;r++){
                        dis[a[e][r]][a[i][j]]=t[e][r]+a[i][j];
                    }
                }
            }
        }
    }
    if(o){
        for(int i=1;i<=q;i++){
            memest(v,0,sizeof(v));
            int x,y;cin>>x>>y;
            cout<<dfs(x,0,y)<<'\n';
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<'\n';
    }
    return 0;
}*/
//bu fen fen lai bu ji xie le
//jiu zhe yang ba
