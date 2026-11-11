#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>
#define int long long
using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

namespace subtask1{
    int n,d;
    int a[(int)2e6+5],dist[(int)2e6+5],count[(int)2e6+5];
    bool isVisited[(int)2e6+5];
    void dijkstra(int s){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        memset(isVisited,false,sizeof isVisited);
        memset(dist,0x3f,sizeof dist);
        memset(count,0,sizeof count);
        isVisited[s]=true;
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto u=pq.top();
            pq.pop();
            for(int v=1;v<=n;++v){
                int w=1;
                if(abs(a[v]-a[u.second])>d||v==u.second){
                    continue;
                }

                if(dist[v]>w+dist[u.second]&&!isVisited[v]){
                    dist[v]=w+dist[u.second];
                    pq.push({dist[v],v});
                    isVisited[v]=true;
                    count[v]=1;
                    // printf("updated: u:%d,v:%d,dist[v]:%d\n",u.second,v,dist[v]);
                }
                else if(dist[v]==w+dist[u.second]){
                    ++count[v];
                    // printf("another shortest: u:%d,v:%d,dist[v]:%d\n",u.second,v,dist[v]);
                }
            }
        }
    }
    void solve(){
        fin>>n>>d;
        for(int i=1;i<=n;++i){
            fin>>a[i];
        }
        int res=0;
        for(int i=1;i<n;++i){
            // cerr<<"-----\n";
            dijkstra(i);

            // for(int j=1;j<=n;++j){
            //     cerr<<dist[j]<<" ";
            // }
            // cerr<<endl;

            for(int j=i+1;j<=n;++j){
                if(count[j]==2){
                    ++res;
                }
            }
        }
        fout<<res<<endl;
    }
}



signed main(){
    int c,t;
    fin>>c>>t;
    while(t--){
        subtask1::solve();
    }
    return 0;
}