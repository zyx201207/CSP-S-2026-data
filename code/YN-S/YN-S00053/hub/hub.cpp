#include<iostream>
#include<vector>
const int N=2e6+11;

std::vector<int>V[N];
int c,t;
int n,k,depth[N];

void dfs(int now,int dpt,int f){
    depth[now]=dpt;
    for(int i:V[now]){
        if(i==f)continue;
        dfs(i,dpt+1,now);
    }
}

void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)V[i].clear();
    
    for(int i=1,v,u;i<n;i++){
        scanf("%d%d",&u,&v);
        V[v].push_back(u);
        V[u].push_back(v);
    }

    dfs(1,0,0);
    int ans=0;
    for(int i=1;i<=n;i++)ans=std::max(ans,depth[i]);
    printf("%d\n",ans/k);
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--)solve();

    return 0;
}
