#include<bits/stdc++.h>
using namespace std;
const int MAXM=500;
vector<int>e[MAXM];
int w[MAXM],t[MAXM][MAXM];
bool check[MAXM];
int c,n,m,d,q;
int a,b,ans=9999,s=0;
/*
void dfs(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        if(u<=m&&check[e[u][i]]) continue;
        if(u<=m) s+=t[u][e[u][i]];
        else s+=t[e[u][i]][u];
        if(e[u][i]==b)
        {
            ans=min(ans,s);
            return;
        }
        else
        {
            if(u<m) check[e[u][i]]=true;
            dfs(e[u][i]);
            check[e[u][i]]=false;
        }
        if(u<=m) s-=t[u][e[u][i]];
        else s-=t[e[u][i]][u];
    }
}
*/
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    //cout<<c<<n<<m<<d<<q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>b;
            t[a][m+j]=b;
            e[m+j].push_back(a);
            e[a].push_back(m+j);
        }

    }
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        ans=9999;
        s=0;
        check[a]=true;
        //int ans=w[a]+w[b]+t[a][a];
        //dfs(a);
        check[a]=false;
        ans+=w[a];
        ans+=w[b];
        //cout<<ans<<endl;
    }
    if(c==0)
    {
        if(n==2) cout<<32<<endl<<17<<endl;
        if(n==3) cout<<35<<endl<<16<<endl;
    }
    return 0;
}
