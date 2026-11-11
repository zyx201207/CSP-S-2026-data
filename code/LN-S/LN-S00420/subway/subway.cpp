#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int C, n, m, d, Q, w[N], len[505], tot, head[N];
int vis[N], fa[N];
long long dis[N];
struct node{
    int idx, t;
    friend bool operator < (node x, node y){
        return x.t > y.t;
    }
};
struct edge{ int nxt, to, t; }e[N];
void addedge(int u, int v, int w){
    e[++tot] = { head[u], v, w };
    head[u] = tot;
    e[++tot] = { head[v], u, w };
    head[v] = tot;
}
int getidx(int way, int pos){ return pos * (d+1) + way; }
int find_(int x){
    if(fa[x] == x) return x;
    return fa[x] = find_(fa[x]);
}

void dij(int s){
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    dis[s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        node u = q.top();
        q.pop();
        //cerr<<u.idx<<" "<<u.t<<":"<<endl;
        if(vis[u.idx]) continue;
        vis[u.idx] = 1;
        for(int i = head[u.idx]; i; i = e[i].nxt){
            int v = e[i].to, w = e[i].t;
            //cerr<<v<<" "<<w<<" "<<endl;
            if(dis[v] > dis[u.idx] + w){
                dis[v] = dis[u.idx] + w;
                //cerr<<dis[v]<<" "<<vis[v]<<endl;
                if(!vis[v]) q.push({v, dis[v]});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d%d", &C, &n, &m, &d, &Q);
    for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= m*d; i++) fa[i] = i;
    for(int i = 1; i <= n; i++){
        scanf("%d", &len[i]);
        int last = 0;
        for(int j = 1; j <= len[i]; j++){
            int pos, idx, tm;
            scanf("%d%d", &pos, &tm);
            idx = getidx(i, pos);
            if(last && find_(last) != find_(idx)) fa[find_(idx)] = find_(last);
            //cout<<idx<<" "<<find_(idx)<<" <-> "<<pos*(d+1)<<" : "<<tm<<endl;
            last = idx;
            addedge(find_(idx), pos*(d+1), tm);//pos*(d+1)为0号点
        }
    }

    while(Q--){
        int s, t, S, T; scanf("%d%d", &s, &t);
        S = s * (d+1); T = t * (d+1);
        //cout<<S<<" "<<T<<endl;
        dij(S);
        printf("%lld\n", dis[T] + w[s] + w[t]);
    }
return 0;
}
