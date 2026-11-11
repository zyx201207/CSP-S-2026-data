#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll,int> pr;
const int N = 2e6+5;
const int mod = 1e9+7;
const int K = 5;
const int inf = 1<<30;
const bool debug = 0;
#define file "subway"
//44 pts
//n<=500
ll c,n,m,d,q;
ll w[N];

int head[N];
int to[N],nxt[N];//belong whitch line
ll cost[N];
int ent = 2;

int queshead[N];
int qto[N],qid[N],qnxt[N];
int qnt = 2;

int ques[N];
ll ans[N];

ll dist[N];
bitset<N> vis;
priority_queue<pr , vector<pr> , greater<pr> > pq;

void addEdge(int u,int v,ll wl){
    to[ent] = v;
    nxt[ent] = head[u];
    cost[ent] = wl;
    head[u] = ent++;
}

void addQues(int u,int v,int id){
    qto[qnt] = v;
    qid[qnt] = id;
    qnxt[qnt] = queshead[u];
    queshead[u] = qnt++;
}

/*
1->enter w[i]
2->into(line k,node x) t k,d
----- start must ---

3->change line int node(line i,line j,node d) t i,d + t j,d

---- end must ----
4->outo(line k,node x) t k,d
5->end w[j]

局限在于我们每次询问都需要去作一次dij，但是明显的是这会超时，然后我们可以想到的是
如果说我们离线处理，
1，预处理无疑是m^2的必死
2，注意到可能会有某个点多次被查询，这下可以缩减一点，但是说实话，这个2*q < m ccf真的会出较水的数据吗
显然我不知道但是不会错，可以试试
*/



ll re();
void judge();
void sol();
void read();
void dij(int u);

int main(){
    if(!debug){
        freopen(file".in","r",stdin);
        freopen(file".out","w",stdout);
    }
    judge();
    return 0;
}



void read(){
    c = re(),n = re(),m = re(),d = re(),q = re();
    for(int i = 1;i <= m;i++){
        w[i] = re();
        //query(i,j) only need to + w[i] + w[j]  
        //idk its meanings 
    }
    for(int i = 1;i <= n;i++){
        int k = re();
        int nd = m+i;
        for(int j = 1;j <= k;j++){
            ll a = re(),t = re();
            addEdge(a,nd,t);
            addEdge(nd,a,t);
        }
    }
}

void judge(){
   read();
   sol();
}


void sol(){
    for(int i = 1;i <= q;i++){
        int u = re(),v = re();
        if(u > v)swap(u,v);
        addQues(u,v,i);
        ques[i] = u;
    }
    sort(ques+1,ques+1+q);
    int nq = 1;
    for(int i = 1;i <= q;i++){
        if(ques[i] != ques[nq]){
            ques[++nq] = ques[i];
        }
    }
    for(int i = 1;i <= nq;i++){
        int u = ques[i];
        // printf("sol%d\n",u);
        dij(u);
        for(int e = queshead[u];e;e=qnxt[e]){
            int v = qto[e],id = qid[e];
            ans[id] = w[u] + w[v] + dist[v];
        }
    }
    for(int i = 1;i <= q;i++){
        printf("%lld\n",ans[i]);
    }
}


void dij(int st){
    
    for(int i = 1;i <= n+m;i++){
        dist[i] = inf;
        vis[i] = 0;
    }
    dist[st] = 0;
    pq.push({0,st});
    while(pq.size()){
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        if(vis[u])continue;
        vis[u] = 1;
        for(int e = head[u];e;e = nxt[e]){
            int v = to[e];
            ll w = cost[e];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}

ll re(){
    ll x = 0,t = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')t = -t;
        ch = getchar();
    }
    while('0' <= ch && ch <= '9'){
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x * t;
} 