#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];//w[i] is the cost from door to the hall in the i-th station 
int k[505];//k[i] is how many stations the i-th line cross
vector<int> a[505];//a[i][j] is the i-th line's j-th station's number(0<=j<k[i])
vector<int> t[505];//t[i][j] is the cost from a[i][j] station hall to line i
long long dis[505][505];
vector<pair<int,int>> station[500005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c/*test numeber*/>>n/*n lines*/>>m/*m station*/>>d/*max lines in one station*/>>q/*T*/;

    for(int i=0;i<505;i++)
    {
        for(int j=0;j<505;j++)
        {
            dis[i][j]=(i==j)?0:1e18;
        }
    }

    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            int tempa,tempt;
            cin>>tempa>>tempt;
            a[i].push_back(tempa),t[i].push_back(tempt);
            station[tempa].push_back(make_pair(i,tempt));
        }
    }

    for(int i=1;i<=m;i++)
    {
        vector<pair<int,int>> v=station[i];
        for(int j=0;j<(int)(v.size()-1);j++)
        {
            for(int k=j+1;k<(int)v.size();k++)
            {
                dis[v[k].first][v[j].first]=dis[v[j].first][v[k].first]=min(dis[v[j].first][v[k].first],(long long)v[j].second+v[k].second);
                //dis[v[k].first][v[j].first]=min(dis[v[k].first][v[j].first],(long long)v[j].second+v[k].second);
            }
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dis[i][k]!=1e12)
                for(int j=i;j<=n;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }   
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dis[i][j]=dis[j][i];
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }*/

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=0;
        ans+=w[x]+w[y];
        long long minn=1e18;
        for(auto i:station[x])
        {
            for(auto j:station[y])
            {
                minn=min(minn,dis[i.first][j.first]+i.second+j.second);
            }
        }
        //cout<<ans<<" "<<minn<<" ";
        ans+=minn;
        cout<<ans<<endl;
    }
    return 0;
}