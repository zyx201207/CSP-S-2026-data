#include<bits/stdc++.h>
using namespace std;
struct sta
{
    long long w;
    vector<long long> a;
    vector<long long> line;
};
sta qq[500005];
long long k[505];
long long dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>qq[i].w;
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int aa,tt;
            cin>>aa>>tt;
            qq[aa].line.push_back(i);
            qq[aa].a.push_back(tt);
            // cout<<qq[aa].line.size()<<endl;;
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        if(qq[i].line.size()<=1)continue;
        for(int j=0;j<qq[i].line.size();j++)
        {
            
            for(int k=j+1;k<qq[i].line.size();k++)
            {
                if(j==k)continue;
                dis[qq[i].line[j]][qq[i].line[k]]=min(dis[qq[i].line[j]][qq[i].line[k]],qq[i].a[j]+qq[i].a[k]);
                dis[qq[i].line[k]][qq[i].line[j]]=dis[qq[i].line[j]][qq[i].line[k]];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //if(dis[i][j]==0x3f3f3f3f3f3f3f3f)continue;
            for(int k=j+1;k<=n;k++)
            {
                //if(dis[i][k]==0x3f3f3f3f3f3f3f3f)continue;
                dis[j][k]=min(dis[j][k],dis[i][k]+dis[j][i]);
                dis[k][j]=dis[j][k];
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(int j=0;j<qq[x].line.size();j++)
        {
            for(int k=0;k<qq[y].line.size();k++)
            {
                //cout<<j<<' '<<k<<endl;
                ans=min(ans,dis[qq[x].line[j]][qq[y].line[k]]+qq[x].w+qq[y].w+qq[x].a[j]+qq[y].a[k]);
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}