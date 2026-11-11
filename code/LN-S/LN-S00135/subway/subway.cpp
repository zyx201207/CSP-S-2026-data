#include<iostream>
#include<queue>
using namespace std;
int c,n,m,d,q;
int w[500001];
int a;//[501][500005];
int t[501][500005];
int k;
bool vis[500005];
struct edge{
    int to;
    int line;
    edge(int a,int b){
        to=a;line=b;
    }
};
vector<edge> g[500001];
int x,y;
int s;
int ans=-1;
void dfs(int u,int line){
    //clog<<"u="<<u<<";line="<<line<<";s="<<s<<"\n";
    if(s>ans && ans!=-1){
        //clog<<"Wrong Way!\n";
        return;
    }
    if(u==y){
        if(ans==-1) ans=s+t[line][u];
        else ans=min(ans,s+t[line][u]);
        //clog<<"END\n";
        return;
    }
    for(auto v:g[u]){
        //clog<<u<<" to "<<v.to<<" :|\n";
        if(vis[v.to]){
            //<<"Continued\n";
            continue;
        };
        int tmp=0;
        if(v.line!=line){
            //clog<<"s+"<<t[line][u]+t[v.line][u]<<"->"<<s+t[line][u]+t[v.line][u]<<"\n";
            //clog<<t[line][u]<<" "<<t[v.line][u]<<"\n";
            tmp=t[line][u]+t[v.line][u];
        }
        vis[v.to]=1;
        s=s+tmp;
        dfs(v.to,v.line);
        s=s-tmp;
        vis[v.to]=0;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        int last=-1;
        for(int j=1;j<=k;j++){
            cin>>a;
            cin>>t[i][a];
            if(last!=-1){
                g[a].push_back(edge(last,i));
                g[last].push_back(edge(a,i));
            }
            last=a;
        }
    }
    for(int i=1;i<=q;i++){
        ans=-1;
        cin>>x>>y;
        //clog<<"x="<<x<<";y="<<y<<"\n";
        vis[x]=1;
        dfs(x,0);
        vis[x]=0;
        cout<<ans+w[x]+w[y]<<"\n";
    }
    /*for(auto v:g[2]){
        clog<<v.to<<",";
    }*/
    return 0;
}
