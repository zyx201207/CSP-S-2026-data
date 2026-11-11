#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n;
ll d;
ll a[500005];
vector<int> g[2000003];
ll dis[2000005],ans[2000005];
bool vis[2000005];
void bfs(int st){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) dis[i]=LONG_MAX;
    memset(ans,0,sizeof(ans));
    dis[st]=0;vis[st]=1;ans[st]=1;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
                ans[v]=ans[u];
            }
            else if(dis[u]+1==dis[v]){
                ans[v]+=ans[u];
            }
        }
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(;t--;){
        ll sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                if(abs(a[i]-a[j])<=d)
                    g[i].push_back(j),g[j].push_back(i);
        /*for(int i=1;i<=n;i++,printf("\n"))
            for(int j=0;j<g[i].size();j++)
                cout<<g[i][j]<<" ";*/
        for(int i=1;i<=n;i++){
            bfs(i);
            //cout<<endl;
            for(int j=1;j<=n;j++){
                //cout<<ans[j]<<" ";
                if(ans[j]==2) sum++;
            }
        }
        cout<<sum/2<<endl;

    }
    return 0;
}
//Oct31==Dec25?
/*
0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*I want to in the JS qirendashang qwq
CCF please let me AC
from limoxuan0712 uid1432277*/
