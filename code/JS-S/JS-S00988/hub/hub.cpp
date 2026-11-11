#include <bits/stdc++.h>
using namespace std;
struct Info {
    int v,num;
    bool operator < (const Info&w) const {
        return v<w.v;
    }
} dist[1010];
int c,t,dist1[1010],d[1010];
vector <int> e[1010];
bool check[1010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for (;t--;){
        int n,k,ans=1<<29;
        queue <int> q;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);}
        int res=-1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dist[j].v=1<<29;
                dist[j].num=j;
            }
            dist[i].v=0;
            q.push(i);
            while (!q.empty()){
                int x=q.front();
                q.pop();
                for (auto y : e[x]){
                    if (dist[y].v>dist[x].v+1){
                        dist[y].v=dist[x].v+1;
                        q.push(y);
                    }
                }
            }
            memset(check,false,sizeof(check));
            sort(dist+1,dist+n+1);
            check[dist[1].num]=true;
            int x=1;
            d[x]=dist[1].num;
            for (int j=1;j<=k;j++){
                check[dist[n-j+1].num]=true;
                x++;
                d[x]=dist[n-j+1].num;
            }
            for (int j=1;j<=n;j++){
                if (!check[j]){
                    memset(dist1,0,sizeof(dist1));
                    memset(check,false,sizeof(check));
                    q.empty();
                    q.push(j);
                    while (!q.empty()){
                        int x=q.front();
                        q.pop();
                        for (auto y : e[x]){
                            if (!check[y]){
                                dist1[y]=dist1[x]+1;
                                q.push(y);
                                check[y]=true;
                            }
                        }
                    }
                    for (int k=1;k<=x;k++)
                        res=max(res,dist1[d[k]]);
                }
            }
            ans=min(ans,res);
        }
        printf("%d\n",ans-2);
    }
    return 0;
}
