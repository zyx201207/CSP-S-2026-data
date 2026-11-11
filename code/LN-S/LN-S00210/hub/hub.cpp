// 查找有 (k+1 个点的树的最小直径，并且度为1的点至少有一个(root特殊处理)) 或 k 个点的最小直径
// 考虑树形dp求直径
// dfs? 边权为1?
// 先dfs求dep，再一点点删叶子节点
// 快速获取到以不同点为根的叶子数量？ dfs序+区间操作no
// 先求重心？
// test

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
const int N=1e6+10;

vector<int> g[N];
int superroot=1,superdep=0;

int dep[N];
int depmax[N];
int depmax2[N];

// basic
int dfs(int d,int u,int fa){
    dep[u]=d;
    for(int v:g[u]){
        if(v==fa){
            continue;
        }
        dfs(d+1,v,u);
    }
}
// with max
int dfs2(int d,int u,int fa){
    dep[u]=d;
    depmax[u]=d;
    for(int v:g[u]){
        if(v==fa){
            continue;
        }
        dfs2(d+1,v,u);
        depmax[u] = max(depmax[u],dep[v]);
    }
}
// get center
int dfs3(int d,int u,int fa){
    int w = (depmax[i]+dep[u]-1)+
    if()
    for(int v:g[u]){
        if(v==fa){
            continue;
        }
        dfs3(d+1,v,u);
    }
}


int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i=1;i<n;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
        }
    }
}

// 如何快速知道是否该选点？
