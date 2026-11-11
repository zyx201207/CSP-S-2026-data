#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int MAXN=5e2+5, MAXM=5e5+5;
vector<long long> len[MAXM];
vector<int> node[MAXM];
long long d[MAXN][MAXN], w[MAXM], ans;
int c, N, M, md, q;
void floyd(){
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                d[i][j]=min(d[i][k]+d[k][j], d[i][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &N, &M, &md, &q);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            d[i][j]=((i==j)?0:INF);
        }
    }
    for(int i=1; i<=M; i++){
        scanf("%lld", &w[i]);
    }
    long long b;
    for(int k, i=1; i<=N; i++){
        scanf("%d", &k);
        for(int a, j=1; j<=k; j++){
            scanf("%d%lld", &a, &b);
            node[a].push_back(i);
            len[a].push_back(b);
        }
    }
    for(int i=1; i<=M; i++){
        for(int j=0; j<node[i].size(); j++){
            for(int k=j+1; k<node[i].size(); k++){
                int x=node[i][j], y=node[i][k];
                d[x][y]=d[y][x]=min(d[x][y], len[i][j]+len[i][k]);
            }
        }
    }
    floyd();
    for(int x, y, i=1; i<=q; i++){
        ans=INF; scanf("%d%d", &x, &y);
        for(int j=0; j<node[x].size(); j++){
            for(int k=0; k<node[y].size(); k++){
                ans=min(ans, d[node[x][j]][node[y][k]]+len[x][j]+len[y][k]);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n", ans);
    }
    return 0;
}
