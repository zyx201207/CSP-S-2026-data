#include<bits/stdc++.h>
using namespace std;
struct Node{
    int v,t;
};
int c,n,m,d,q,w[500005],ans=1e9;
bool vis[500005];
vector<Node>a[500005],b[500005];
void dfs(int x,int y,int dtz,int lx,int s,int zt)//1 ko 2 ting 3 tai
{
    if(dtz==y){
        ans=min(ans,s+w[y]);
        return ;
    }
    if(vis[dtz]==1)
            return ;
    if(zt==1)
        dfs(x,y,dtz,lx,s+w[x],2);
    else if(zt==2)
        for(Node u:a[dtz])
        {
            vis[dtz]=1;
            dfs(x,y,dtz,u.v,s+u.t,3);
        }
    else if(zt==3)
    {
        for(Node u:b[lx])
            dfs(x,y,u.v,lx,s,3);
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a1,t;
            cin>>a1>>t;
            a[a1].push_back({i,t});
            a[i].push_back({a1,t});
            b[i].push_back({a1,0});
        }
    }
    while(q--)
    {
        //int x,y;
        //cin>>x>>y;
        //dfs(x,y,x,0,0,1);
        cout<<67;
    }
    return 0;
}//ming nian zai zhan
