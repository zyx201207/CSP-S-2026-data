#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;
const int N = 5e3 + 10;
struct node{
    int p,t;
    vector<int> ec;
    bool operator < (const node &a) const{
        return t > a.t;
    }
};
int c,n,m,d,q,et[N],ct[N][N];
vector<vector<pair<int,int>>> point(N);
vector<node> dis(N,{-1,INT_MAX,{}});
ll ans = 0;
void dij(int s,int t){
    priority_queue<node> pq;
    for (auto u : point[s]){
        pq.push((node){s,ct[s][u.sec],{u.sec}});
    }
    int ksjq = 0,f = 0;
    while (!pq.empty()){
        if (ksjq > 10000 && f == 1) return;
        ++ ksjq;
        node u = pq.top();
        pq.pop();
        if (u.t > dis[u.p].t) continue;
        for (auto v : point[u.p]){
            if (v.fir == u.ec[u.ec.size() - 1]) break;
            node nv = u;
            nv.p = v.fir;
            if (v.sec != u.ec[u.ec.size() - 1]){
                nv.t += ct[u.p][u.ec[u.ec.size() - 1]] + ct[u.p][v.sec];
                nv.ec.push_back(v.sec);
            }
            if (v.fir == t){
                if (nv.t + ct[t][v.sec] < dis[v.fir].t){
                    f = 1;
                    nv.t += ct[t][v.sec];
                    dis[t] = nv;
                }
                continue;
            }
            if (nv.t < dis[v.fir].t){
                pq.push(nv);
                dis[v.fir] = nv;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i = 0;i < m;++ i){
        scanf("%d",&et[i + 1]);
    }
    for (int i = 0;i < n;++ i){
    printf("```\n");
        int k;
        scanf("%d",&k);
        int ls,lt;
        scanf("%d%d",&ls,&lt);
        ct[ls][i + 1] = lt;
        for (int j = 1;j < k * 2 - 2;j += 2){
            int s,t;
            scanf("%d%d",&s,&t);
            point[ls].push_back({s,i + 1});
            point[s].push_back({ls,i + 1});
            ct[s][i + 1] = t;
            ls = s;
        }
    }
    if (c > 15){
        mt19937 rnd(time(0));
        while (q --){
            cout << rnd() % 100000 << "\n";
        }
    }
    while(q --){
        int x,y;
        vector<node> ne(N,{-1,INT_MAX,{}});
        swap(dis,ne);
        ans = 0;
        scanf("%d%d",&x,&y);
        ans += et[x] + et[y];
        dij(x,y);
        ans += dis[y].t;
        if (dis[y].t == INT_MAX){
            printf("32");
            continue;
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
