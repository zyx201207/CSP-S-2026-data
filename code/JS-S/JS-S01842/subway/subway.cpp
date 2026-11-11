#include<bits/stdc++.h>
using namespace std;
/*////////////////////////////////////////////////////*/const long long miku=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q,w[500005];
long long g[505][505];
vector<long long>a[505];
vector<long long>t[505];
//map<long long,vector<long long>> mp;
//map<long long,map<long long,long long>> ttt;
//set<int> not_useless;
struct kards
{
    long long st,id;
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j]=miku;
        }
    }
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
            long long aa,tt;
            cin>>aa>>tt;
            a[i].push_back(aa);
            t[i].push_back(tt);
            //ttt[i][aa]=tt;
        }
    }
      /* if(m<=5000)
    {
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            mp[a[i][j]].push_back(i);
            not_useless.insert(a[i][j]);
        }
    }
    for(auto e:not_useless)
    {
       // cout<<e<<endl;
        for(auto f:mp[e])
        {
            for(auto h:mp[e])
            {
                g[f][h]=g[h][f]=min(g[h][f],ttt[f][e]+ttt[h][e]);
            }
        }
    }}*/
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            for(int k=i;k<=n;k++)
            {
                for(int p=0;p<a[k].size();p++)
                {
                    if(a[i][j]==a[k][p])
                    {
                        g[k][i]=g[i][k]=min(g[i][k],t[i][j]+t[k][p]);
                    }
                }
            }
        }
    }
    
 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(int i=1;i<=n;i++)
    {
        g[i][i]=0;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[j][k]);
            }
        }
    }


    while(q--)
    {
        long long s,e;
        cin>>s>>e;
        vector<kards>ss;
        vector<kards>ee;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]==s)
                {
                    ss.push_back({i,j});
                }
                if(a[i][j]==e)
                {
                    ee.push_back({i,j});
                }
            }
        }
        long long ans=miku;
        for(int i=0;i<ss.size();i++)
        {
            for(int j=0;j<ee.size();j++)
            {
                ans=min(ans,g[ss[i].st][ee[j].st]+w[s]+w[e]+t[ss[i].st][ss[i].id]+t[ee[j].st][ee[j].id]);
            }
        }
        cout<<ans<<endl;
    }
}
//??：?? 开考前听同考场人说codeblocks能玩俄罗斯方块，真的假的
//??：?? （暴戾语言）！好像是真的！