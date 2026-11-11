#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,leave[1000005],num[1000005];
queue<int> q;
void dfs(int a,int fa){
    for (auto e[a]:node){
        num[node]=num[a]+1;
        if (e[node][3]==0)
            dfs()
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for (int i=1;i<=n-1;i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i=1;i<=n;i++)
            if (e[i]==0)
                leave[i]=1;
        for (int i=1;i<=n;i++)
            if (leave[i])
                q.push(i);
        while (q.size()){
            int node=q.top();
            q.pop();
            dfs(node,0);
        }
    }
    return 0;
}
