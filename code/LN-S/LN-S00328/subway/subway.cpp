#include<bits/stdc++.h>
using std::vector;
using std::min;
int testid , waynum , snsnum , maxway , qnum ;
int vexnum=0 ;
struct station{
    int center;
    vector<int> ways;
} sns[500500] ;
int add[500500] ;
struct edges_t{
    int to , len ;
};
edges_t make_edges_t(int _to , int _len){
    edges_t res;
    res.to=_to;
    res.len=_len;
    return res;
}
vector<vector<edges_t>> edges ;
void add_edge(int x,int y,int z){
    edges[x].push_back(make_edges_t(y,z));
    edges[y].push_back(make_edges_t(x,z));
}
namespace Floyd{
    vector<vector<long long>> dist ;
    void init(){
        dist.assign(vexnum+1,vector<long long>(vexnum+1,(long long)(1e18)));
        for(int i=1;i<=vexnum;i++){
            for(auto j:edges[i]){
                dist[i][j.to]=dist[j.to][i]=j.len;
            }
        }
        for(int k=1;k<=vexnum;k++){
            for(int j=1;j<=vexnum;j++){
                for(int i=1;i<=vexnum;i++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    long long calc(int x,int y){return dist[x][y];}
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&testid,&waynum,&snsnum,&maxway,&qnum);
    edges.assign(snsnum*maxway+snsnum+1,vector<edges_t>());
    for(int i=1;i<=snsnum;i++){
        scanf("%d",&add[i]);
        sns[i].center=++vexnum;
    }
    for(int i=1;i<=waynum;i++){
        int waysns ;
        scanf("%d",&waysns);
        int last_id=-1;
        for(int j=1;j<=waysns;j++){
            int snsid , _time ;
            scanf("%d%d",&snsid,&_time);
            sns[snsid].ways.push_back(++vexnum);
            add_edge(vexnum,snsid,_time);
            if(j>1){
                add_edge(last_id,vexnum,0);
            }
            last_id=vexnum;
        }
    }
    Floyd::init();
    while(qnum--){
        int x , y ;
        scanf("%d%d",&x,&y);
        printf("%lld\n",Floyd::calc(sns[x].center,sns[y].center)+1LL*add[x]+1LL*add[y]);
    }
    return 0;
}
