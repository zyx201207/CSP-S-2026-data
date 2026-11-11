#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=2e6+5;
int d[N],cnt[N];
long long x[N];
vector<int> e[N];
void bfs(int st){
    memset(d,-1,sizeof(d));
    d[st]=0;
    cnt[st]=1;
    queue<int> q;
    q.push(st);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int v:e[u]){
            if (d[v]==-1){
                d[v]=d[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else if (d[u]+1==d[v]) cnt[v]++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while (t--){
        int n;
        long long d;
        scanf("%d %lld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
            e[i].clear();
        }
        for (int u=1;u<=n;u++){
            for (int v=u+1;v<=n;v++){
                if (x[v]-x[u]<=d){
                    e[u].push_back(v);
                    e[v].push_back(u);
                }
            }
        }
        int ans=0;
        for (int u=1;u<=n;u++){
            bfs(u);
            for (int v=u+1;v<=n;v++){
                if (cnt[v]==2){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
