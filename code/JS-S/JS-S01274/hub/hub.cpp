#include <bits/stdc++.h>
using namespace std;

int c,T;

int n,k;
int a,b;
vector <int> p[2000005];

bool vis[2000005];
int dis[2000005];
int d[2000005];

int fa[2000005];

void dfs(int u,int fa){
    for(auto v:p[u]){
        if(fa==v) continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void init(int n){
    for(int i=1;i<=n;i++)
        p[i].clear();
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T){
        T--;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            p[b].push_back(a);
            p[a].push_back(b);
        }
        if(k==n){
            printf("0\n");
            init(n);
            continue;
        }else if(k>=(n+1)/2){
            printf("1\n");
            init(n);
            continue;
        }
        int ans=20000000;
        for(int s=1;s<(1<<n);s++){
            int cnt=0;
            for(int i=0;i<n;i++){
                fa[i+1]=i+1;
                d[i+1]=20000000;
                if((s>>i)&1)
                    cnt++;
            }
            if(cnt!=k) continue;
            for(int i=1;i<=n;i++){
                if(!(s>>(i-1)&1)) continue;
                int x=find(i);
                for(int j=0;j<p[i].size();j++){
                    if(!(s>>(p[i][j]-1)&1)) continue;
                    int y=find(p[i][j]);
                    if(x!=y){
                        fa[y]=x;
                        cnt--;
                    }
                }
            }
            if(cnt>2) continue;
            int mx=0;
            for(int i=1;i<=n;i++){
                if(!(s>>(i-1)&1)) continue;
                dis[i]=0;
                dfs(i,-1);
                for(int j=1;j<=n;j++)
                    d[j]=min(d[j],dis[j]);
            }
            for(int i=1;i<=n;i++)
                mx=max(mx,d[i]);
            ans=min(ans,mx);
        }
        printf("%d\n",ans);
        init(n);
    }
    return 0;
}
