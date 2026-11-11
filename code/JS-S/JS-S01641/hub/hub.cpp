#include<bits/stdc++.h>
using namespace std;
int n,k,ans=100;
int dis[1010][1010];
void init()
{
    memset(dis,0x3f,sizeof(dis));
    cin>>n>>k;
    ans=100;
    for(int i=1;i<n;i++)
    {
       int u,v;
       cin>>u>>v;
       dis[u][u]=0;
       dis[v][v]=0;
       dis[u][v]=1;
       dis[v][u]=1;
    }
}
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
}
vector<int> v;
void solve1()
{
    floyd();
    for(int i=0;i<(1<<n);i++)
    {
        v.clear();
        int j=i;
        for(int l=1;l<=n;l++)
        {
            if(j%2==1) v.push_back(l);
            j/=2;
        }
        if(v.size()==k)
        {
            int cnt=0;
            for(int l=1;l<v.size();l++)
                for(int m=0;m<l;m++)
                    if(dis[v[m]][v[l]]==1)
                    {
                        cnt++;
                        break;
                    }
            if(cnt>=k-2)
            {
                int sum=0;
                for(int l=1;l<=n;l++)
                {
                    int dist=100;
                    for(int m=0;m<v.size();m++)
                        dist=min(dist,dis[l][v[m]]);
                    sum=max(sum,dist);
                }
                ans=min(ans,sum);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        init();
        if(k<=10) solve1();
    }
    return 0;
}
