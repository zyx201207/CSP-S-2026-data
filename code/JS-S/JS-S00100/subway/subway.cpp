#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
int w[500+10];
vector<int> g[500+10];
vector<int> g1[500+10];
int ans[500+10][500+10];
vector<pair<int,int>> g2[500000+10];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[i].push_back(a);
            g1[i].push_back(t);
            g2[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) ans[i][j]=0;
            else ans[i][j]=1e14;
        }
    }    
   
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int l=0;l<g[j].size();l++)
            {
                for(int k=0;k<g[i].size();k++)
                {
                    if(g[i][k]==g[j][l])
                    {
                        int x=g[i][k];
                        int y=g[j][l];
                       //cout<<x<<" "<<y<<ln;
                        ans[i][j]=min(ans[i][j],g1[i][k]+g1[j][l]);
                        ans[j][i]=ans[i][j];
                        //cout<<i<<" "<<j<<ln;
                        //cout<<"a"<<ans[i][j]<<" "<<ans[j][i]<<ln;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(k==j||k==i) continue;
                ans[i][j]=min(ans[i][j],ans[i][k]+ans[j][k]);
                ans[j][i]=ans[i][j];
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<ln;
    // }
    // cout<<ln;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ansz=1e14;
        for(auto i:g2[x])
        {
            for(auto j:g2[y])
            {
                int a=i.first;
                int b=j.first;
                //cout<<ans[a][b]<<ln;
                int ans1=i.second+j.second+ans[a][b];
                ansz=min(ansz,ans1);
            }
        }
        cout<<ansz+w[x]+w[y]<<ln;
        //cout<<ln;
    }
    return 0;
}