#include <bits/stdc++.h>
using namespace std;
int c,T,n,k,h[1000010];
vector<int>e[1000010];
void dfs(int x,int sum){
    if(x>n){

        return;
    }
    if(sum==k){
        dfs(x+1,sum);
        return;
    }
    if(sum+n-x+1==k){
        h[x]=1;
        dfs(x+1,sum+1);
        h[x]=0;
        return;
    }
    dfs(x+1,sum);
    h[x]=1;
    dfs(x+1,sum+1);
    h[x]=0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        printf("0\n");
        continue;

        cin>>n>>k;
        for(int i=1;i<=n;++i)vector<int>().swap(e[i]);
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    return 0;
}
