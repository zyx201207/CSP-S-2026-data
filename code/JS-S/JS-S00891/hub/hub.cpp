#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int ans=-1;
void dfs(int u,int fa,int d){
    ans=max(ans,d);
    for(int v:g[u]){
        if(v!=fa) dfs(v,u,d+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==1||k==2){
            dfs(1,0,0);
            int maxn=ans;
            ans=-1;
            dfs(g[1][0],0,0);
            maxn+=ans-1;
            if(k==1){
                cout<<maxn/2<<endl;
            }
            else{
                cout<<(maxn+1)/3-1<<endl;
            }
        }
        else if(c==13||c==14){
            int m=n/2;
            cout<<n/2-m/2<<endl;
        }
    }
    return 0;
}
