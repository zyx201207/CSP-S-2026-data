#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
//居然告诉代码测试点编号？考骗分的题吗...
//我已经有点累了，读不懂
//go to read T3 and T4
//I even don't know what did they say
//拜图灵。不爆零
//orz
//我先看看哪些点貌似在我能力范围内吧
//1-3 DFS 12pts 不会阿
//7-11 预处理一下，然后查询 20pts
//12-19 当无权图去做？ 45pts
//21，22看起来有点意思，一会研究下有什么用
//已经读了45 min 了
//15:55 开写开写
//16:15不会阿开溜
//后面的题都写了骗分，回来了
// 7-11 20pts 18:04
const int MAXN = 505;
const int MAXM = 5e5+5;
const int INF = 0x3f3f3f3f;
int w[MAXM];
vector<vector<pair<int,int>>> g(MAXN);
int c,n,m,d,q;
struct edge{
    int v,w;
};
vector<vector<edge>> e(MAXN);
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++) cin>>w[i];
    if(c>=7&&c<=11){
        for(int i = 1;i<=n;i++){
            int k;
            cin>>k;
            if(k==1) continue;
            int u,w1,v,w2;
            cin>>u>>w1>>v>>w2;
            e[u].push_back({v,w1+w2});
            e[v].push_back({u,w1+w2});
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            long long ans = w[x]+w[y];
            int dis[MAXN];
            //dijkstra 忘了！let me bfs
            for(int i = 1;i<=n;i++) dis[i] = INF;
            dis[x] = 0;
            queue<int> qu;
            qu.push(x);
            while(!qu.empty()){
                int u = qu.front();
                qu.pop();
                for(auto ed:e[u]){
                    int v = ed.v,w = ed.w;
                    if(dis[v]>dis[u]+w){
                        qu.push(v);
                        dis[v] = dis[u]+w;
                    }
                }

            }
            cout<<ans+dis[y]<<"\n";

        }
        return 0;
    }
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        for(int j = 1;j<=k;j++){
            pair<int,int> cur;
            cin>>cur.first>>cur.second;
            g[i].push_back(cur);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(c<=3){
            int ans = w[x]+w[y];
            cout<<ans<<"\n";
        }
    }
}
