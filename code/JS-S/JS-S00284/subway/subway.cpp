//Entrance to The Chaos
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<pair<int,int> > st_li_ma[500005];//<number,time>
int st_li_l[500005];
//int st_to_li[500005][505];//distance of station to line
int dis[505][505];//distance between lines
int ma[505][505];//original distance between lines
int entry[500005];//time for enter the sation
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld\n",&c,&n,&m,&d,&q);
    memset(dis,-1,sizeof(dis));
    memset(ma,-1,sizeof(ma));
    //memset(st_to_li,-1,sizeof(st_to_li));
    for(int i=1;i<=m;i++)
    {
        //cin>>entry[i];
        scanf("%lld ",&entry[i]);
    }
    for(int i=0;i<n;i++)
    {
        int l;
        scanf("%lld ",&l);
        for(int j=0;j<l;j++)
        {
            int a,t;
            scanf("%lld %lld",&a,&t);
            //st_to_li[a][i]=t;
            st_li_ma[a].push_back(make_pair(i,t));
            st_li_l[a]++;
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<st_li_l[i];j++)
        {
            for(int k=j+1;k<st_li_l[i];k++)
            {
                int x=st_li_ma[i][j].first,y=st_li_ma[i][k].first;
                int l=st_li_ma[i][j].second+st_li_ma[i][k].second;
                if(x>y)
                {
                    swap(x,y);
                }
                if(ma[x][y]==-1)
                {
                    ma[x][y]=l;
                }
                else
                {
                    ma[x][y]=min(ma[x][y],l);
                }
                if(dis[x][y]==-1)
                {
                    dis[x][y]=ma[x][y];
                }
                else
                {
                    dis[x][y]=min(dis[x][y],ma[x][y]);
                }
                ma[y][x]=ma[x][y];
                dis[y][x]=dis[x][y];
            }
        }
    }
    for(int i=0;i<n;i++)
    {

        dis[i][i]=0;
    }
    for(int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dis[i][k]!=-1&&dis[k][j]!=-1)
                {
                    if(dis[i][j]==-1)
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                    else
                    {
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                    dis[j][i]=dis[i][j];
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%lld %lld\n",&x,&y);
        int ans=LONG_LONG_MAX;
        for(int i=0;i<st_li_l[x];i++)
        {
            for(int j=0;j<st_li_l[y];j++)
            {
                int a=st_li_ma[x][i].first,b=st_li_ma[y][j].first;
                int t1=st_li_ma[x][i].second+st_li_ma[y][j].second;
                int te=t1+dis[a][b];
                ans=min(ans,te);
            }
        }
        printf("%lld\n",ans+entry[x]+entry[y]);
    }
}
