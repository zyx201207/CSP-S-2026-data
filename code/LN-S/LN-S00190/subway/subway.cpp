#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
struct station{
    long long line,t;
};
vector<vector<station>> vv[500005];
vector<vector<long long>> li[505];
bool vis[500005];
long long ans=1e12;
struct node{
    long long step,sta;
};
queue<node> qu;
void bfs(long long x,long long y,long long step){
    vis[x]=true;
    qu.push({x,step});
    while(!qu.empty()){
        node st=qu.front();
        qu.pop();
        if(st.sta==y){
            ans=min(ans,step);
            continue;
        }
        for(long long i=1;i<=vv[x].size();i++){
            long long lin=vv[x][i].line;
            for(long long j=1;j<=li[lin].size();j++){
                if(!vis[li[lin][j]]) {
                    vis[li[lin][j]]=true;
                    qu.push({li[lin][j],step++});
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    long long T;
    for(long long i=1;i<=m;i++) cin>>m[i];
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            long long a,t;
            cin>>a>>t;
            vv[a].push_back({i,t});
            li[i].push_back(a);
            T=t;
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        bfs(x,y,1);
        cout<<ans*T+w[x]+w[y]<<endl;
        ans=1e12;
        for(int i=1;i<=m;i++) vis[i]=false;
    }
    return 0;
}
