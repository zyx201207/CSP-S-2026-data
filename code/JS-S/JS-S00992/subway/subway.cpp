#include<bits/stdc++.h>
using namespace std;
int w[511111];
int k[1111];
int a[1111][1111],t[1111][1111];
int x[111111],y[111111];
struct egg{
    int b,c;
};
vector<egg> v[511111];
set<pair<int,int>> st;
//int fa[511111];
bool vis[511111];
int ans[511111];
/*int find(int x)
{
    int u=fa[x];
    if(x==u)
        return u;
    return fa[x]=find(u);
}*/
void djd(int s)
{
    memset(vis,0,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    st.insert({0,s});
    ans[s]=0;
    while(!st.empty())
    {
        pair<int,int> ss=*st.begin();
        for(egg x:v[ss.second])
        {
            if(vis[x.b]==0)
            {
                st.insert({x.c,x.b});
                vis[x.b]=1;
            }
            ans[x.b]=min(ans[ss.second]+x.c,ans[x.b]);
        }
        st.erase(ss);
        vis[ss.second]=1;
    }
}
int main()
{
    freopen("subway6.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(ans,0x3f,sizeof(ans));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
        //fa[i]=i;
    } 
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            for(int kk=0;kk<j;kk++)
            {
                v[a[i][kk]].push_back({a[i][j],(t[i][j]+t[i][kk])});
                v[a[i][j]].push_back({a[i][kk],(t[i][j]+t[i][kk])});
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x[i]>>y[i];
        djd(x[i]);
        cout<<ans[y[i]]+w[y[i]-1]+w[x[i]-1]<<endl;
    }
        
    return 0;
}