#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ifstream fin("subway.in");
ofstream fout("subway.out");

int c,n,m,d,q;

const int inf=1e9;

const int maxn=1e6+10;
int w[maxn];


struct edge{
    int to;
    int v;
    bool operator<(const edge&other)const{
        return v<other.v;
    }
    bool operator>(const edge&other)const{
        return v>other.v;
    }
};

int main(){
    fin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++)fin>>w[i];
    vector<vector<int>>adj1(n+10,vector<int>(n+10,inf));//zhan tai
    vector<vector<int>>adj2(m+10,vector<int>(n+10,inf));//zhong zhuan zhan

    vector<vector<edge>>adj3(m+10);

    for(int i=1;i<=n;i++){
        int k;
        fin>>k;
        for(int i=0;i<k;i++){
            int a,t;
            fin>>a>>t;
            adj2[a][i]=t;
            adj3[a].push_back({i,t});
        }
    }

    vector<vector<int>>dist(n+1,vector<int>(n+1,inf));//zhan tai dao zhan tai

    for(int i=1;i<=m;i++){//wei zhan dao zhan lian bian
        for(int from=1;from<=n;from++){
            for(int to=from+1;to<=n;to++){
                adj1[from][to]=min(adj1[from][to],adj2[i][from]+adj2[i][to]);
                adj1[to][from]=adj1[from][to];
            }
        }
    }

    for(int i=1;i<=n;i++){//chu li zhan dao zhan de zui duan lu
        int from=i;
        dist[from][from]=0;
        priority_queue<edge,vector<edge>,greater<edge>>q;
        q.push({from,0});
        vector<bool>vis(m+10,false);
        vis[from]=true;

        while(!q.empty()){
            int now=q.top().to;
            int v=q.top().v;
            q.pop();
            vis[now]=true;
            dist[from][now]=v;
            for(int nxt=1;nxt<=n;nxt++){
                if(vis[nxt]||adj1[now][nxt]==inf)continue;
                int nxt_v=v+adj1[now][nxt];
                if(nxt_v>=dist[from][nxt])continue;
                q.push({nxt,nxt_v});
                vis[nxt]=true;
            }
        }
    }
    for(int i=0;i<q;i++){//mei ju liang ge xian lu
        int x,y;
        fin>>x>>y;
        ll ans=inf;
        for(int a=0;a<adj3[x].size();a++){
            for(int b=0;b<adj3[y].size();b++){
                ans=min(ans,
                            (ll)w[x]+w[y]
                            +adj2[x][adj3[x][a].to]
                            +adj2[y][adj3[y][b].to]
                            +dist[a][b]);
            }
        }
        fout<<ans<<"\n";
    }
}