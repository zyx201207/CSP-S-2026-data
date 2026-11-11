#include <bits/stdc++.h>
using namespace std;
const int N = 512, M = 500050, E = 22;
const long long  VERY_BIG = 1ll<<50;//E is D
typedef long long ll;
int c;
int n, m, d, q;
int subcnt[M], k[N], head[M], st, en;
ll dist[N][N], w[M], ans;
struct edge{
    int subid, next, sublen;
}e[M*E];
int ent=0;
void addedge(int platid, int subid, ll sublen){
    ent++;
    e[ent].subid = subid;
    e[ent].next = head[platid];
    e[ent].sublen = sublen;
    head[platid] = ent;
    subcnt[platid]++;
    return;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i=1;i<=m;i++){
        scanf("%lld", &w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &k[i]);
        for(int j=1;j<=k[i];j++){
            int u; ll v;
            scanf("%d%lld", &u, &v);
            addedge(u, i, v);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dist[i][j] = VERY_BIG;
        }
    }
    for(int platid=1;platid<=m;platid++){
        for(int i=head[platid];i;i=e[i].next){
            int subid1 = e[i].subid;
            ll sublen1 = e[i].sublen;
            for(int j=head[platid];j;j=e[j].next){
                int subid2 = e[j].subid;
                ll sublen2 = e[j].sublen;
                if(subid1==subid2) continue;
                dist[subid1][subid2] = sublen1 + sublen2;
                dist[subid2][subid1] = sublen2 + sublen1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j||j==k||k==i) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        scanf("%d%d", &st, &en);
        ans = VERY_BIG;
        for(int i=head[st];i;i=e[i].next){
            int subid1 = e[i].subid;
            ll sublen1 = e[i].sublen;
            for(int j=head[en];j;j=e[j].next){
                int subid2 = e[j].subid;
                ll sublen2 = e[j].sublen;
                ans = min(ans, sublen1+dist[subid1][subid2]+sublen2);
            }
        }
        ans += w[st] + w[en];
        printf("%lld\n", ans);
    }
    return 0;
}