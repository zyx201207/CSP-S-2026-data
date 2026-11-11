#include<fstream>
#include<vector>
#include<queue>
std::ifstream fin("subway.in");
std::ofstream fout("subway.out");
long long c,n,m,d,q;
const int maxm=20004;
long long wcd[maxm];
long long k[502];
long long tre[502][maxm];
long long INF=1LL<<60;
std::vector<int> change[maxm];
std::vector<std::pair<long long,std::pair<int,int>>> adj[502][maxm];
long long solve(int x,int y){
    long long dis[n+10][m+10];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            dis[i][j]=INF;
        }
    }
    std::priority_queue<std::pair<long long,std::pair<int,int>>,std::vector<std::pair<long long,std::pair<int,int>>>,std::greater<std::pair<long long,std::pair<int,int>>>> que;
    dis[0][x]=0;
    que.push({0,{0,x}});
    while(!que.empty()){
        auto node=que.top();
        que.pop();
        long long ds=node.first;
        int rail=node.second.first;
        int station=node.second.second;
        if(ds!=dis[rail][station]){
            continue;
        }else if(rail==0 and station==y){
            return ds;
        }else{
            for(auto e:adj[rail][station]){
                long long eds=e.first;
                int erail=e.second.first;
                int estation=e.second.second;
                if(ds+eds<dis[erail][estation]){
                    dis[erail][estation]=ds+eds;
                    que.push({dis[erail][estation],{erail,estation}});
                }
            }
        }
    }
    return dis[0][y];
}

int main(){
    fin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        fin>>wcd[i];
    }
    for(int i=1;i<=n;++i){
        fin>>k[i];
        int last=0;
        for(int j=1;j<=k[i];++j){
            int a;
            fin>>a;
            change[a].push_back(i);
            fin>>tre[i][a];
            if(j!=1){
                adj[i][last].push_back({0,{i,a}});
                adj[i][a].push_back({0,{i,last}});
            }
            last=a;
        }
    }
    for(int i=1;i<=m;++i){
        for(auto u:change[i]){
            /*for(auto v:change[i]){
                if(u!=v){
                    adj[u][i].push_back({tre[u][i]+tre[v][i],{v,i}});
                    adj[v][i].push_back({tre[u][i]+tre[v][i],{u,i}});
                }
            }*/
            adj[0][i].push_back({tre[u][i],{u,i}});
            adj[u][i].push_back({tre[u][i],{0,i}});
        }
    }
    while(q-->0){
        int x,y;
        fin>>x>>y;
        fout<<wcd[x]+wcd[y]+solve(x,y)<<'\n';
    }
}
