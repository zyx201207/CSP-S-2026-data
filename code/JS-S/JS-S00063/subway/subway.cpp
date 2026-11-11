#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=5e2+4,maxm=5e5+4;
struct node{
    int x,y;
};
vector<node>G[maxm];
int C,n,m,d,q;
int w[maxm],k[maxn];
ll adj[maxn][maxn];
//int a[maxn][maxm],t[maxn][maxm];//!!!MLE!!!

vector<int>a[maxn];
vector<ll>t[maxn];

bool inq[maxn],vis[maxm];


void bfs(){
    //cout<<"*";
    queue<int>q;
    q.push(1);
    inq[1]=1;
    while(!q.empty()){
        int id=q.front();
        q.pop();
        //cout<<id<<"*\n";
        for(int i=1;i<=k[id];i++){
            int u=a[id][i];
            //cout<<'('<<i<<' '<<u<<endl;
            for(auto e:G[u]){
                ll v=e.x,j=e.y;
                //cout<<'['<<v<<endl;
                if(v==id) continue;

                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                }
                ll x=min(adj[id][v],t[id][i]+t[v][j]);
                adj[id][v]=x;
                adj[v][id]=x;

            }
        }
    }

}


signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //cout<<(&en-&st)/1024/1024;

    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++){
            ll A,T;
            cin>>A>>T;
            G[A].push_back({i,j});
            a[i].push_back(A);
            t[i].push_back(T);
        }
    }
    memset(adj,0x3f,sizeof(adj));
    bfs();
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                adj[j][i]=adj[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++) adj[i][i]=0;
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto u:G[x]){
            for(auto v:G[y]){
                ll s=u.x,r=v.x;
                ll c=adj[s][r]+t[s][u.y]+t[r][v.y];
                ans=min(ans,c);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
