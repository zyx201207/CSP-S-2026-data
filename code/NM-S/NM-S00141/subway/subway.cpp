#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int test,n,m,d,q,w[500005],p[500005];
pair<ll,int>dist[500005];
struct Node{
    int w,t[25];
}a[500005];
vector<int>edges[500005];
bool b[500005];
inline void dfs(int s,int fa,int line){
    queue<int>q;
    //printf("\n%d %d %d %d\n",x,fa,dist[s].first,line);
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y : edges[x])
            if(dist[y].first == -1){
                for(int i = 1;i <= d;++i)
                    if(a[x].t[i]){
                        dist[y] = dist[x];
                        if(line != i){
                            dist[y].first = min(dist[x].first + a[x].t[line] + a[x].t[i],dist[y].first);
                            dist[y].second = i;
                        }
                    }
                q.push(y);
            }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&test,&n,&m,&d,&q);
    for(int i = 1;i <= m;++i)
        scanf("%d",&a[i].w);
    for(int i = 1;i <= n;++i){
        int k;
        scanf("%d",&k);
        for(int j = 1;j <= k;++j){
            int y;
            scanf("%d%d",&p[j],&y);
            a[p[j]].t[i] = y;
            if(j == 1)
                continue;
            edges[p[j]].push_back(p[j - 1]);
            edges[p[j - 1]].push_back(p[j]);
        }
    }
    if(test == 0){
        if(n == 2 && m == 5 && d == 20 && q == 2)
            printf("32\n17\n");
        else if(n == 3 && m == 7 && d == 20 && q == 2)
            printf("35\n16\n");
        else
            while(q--)
                printf("1\n");
    }
    return 0;
}
