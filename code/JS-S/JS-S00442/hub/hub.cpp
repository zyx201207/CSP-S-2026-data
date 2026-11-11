#include<bits/stdc++.h>
using namespace std;
int c,t;
short vis[1000010];
vector<int>road[1000010];
int minn=0x3f3f;
void dfs(int k,int id)
{
    if(k==0)return;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        road[u].push_back(v);
        road[v].push_back(u);
    }

    return 0;
}
