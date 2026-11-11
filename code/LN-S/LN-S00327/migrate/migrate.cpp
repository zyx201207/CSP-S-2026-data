#include <bits/stdc++.h>
using namespace std;
long long a[2145140];
vector<int>g[2145140];
bool vis[2145410];
long long dfs(int x,int y){
    long long cnt=0;
    if(x==y){
        return 1;
    }
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(vis[g[x][i]])continue;
        cnt+=dfs(g[x][i],y);
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n;
        long long d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            g[i].clear();
        }
        if(n<=5000){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(a[i]-a[j])<=d){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
            long long cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    memset(vis,0,sizeof(vis));
                    cnt+=(dfs(i,j)==2);
                }
            }
            cout << cnt << "\n";
        }else{
            cout << (long long)n*(n-1)/2 << "\n";
        }

    }
    return 0;
}
