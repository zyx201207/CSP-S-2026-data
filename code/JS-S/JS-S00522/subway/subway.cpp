#include<iostream>
#include<cstring>
#define N 1000001
using namespace std;
int c,n,m,d,q,t[N],mp[1001][1001];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    memset(mp,0x3f,sizeof mp);
    for(int i=1;i<=1000;i++) mp[i][i]=0;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c<=6)
    {
        for(int i=1;i<=m;i++) cin>>t[i];
        for(int i=1;i<=n;i++)
        {
            int nn;
            cin>>nn;
            for(int j=1,x,ti;j<=nn;j++) cin>>x>>ti,mp[m+i][x]=mp[x][m+i]=ti;
        }
        for(int k=1;k<=n+m;k++)
        {
            for(int i=1;i<=n+m;i++)
            {
                for(int j=1;j<=n+m;j++)
                {
                    if(mp[i][j]>mp[i][k]+mp[k][j]) mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<mp[x][y]+t[x]+t[y]<<endl;
        }
    }
    if(c>=7&&c<=11)
    {
        for(int i=1;i<=m;i++) cin>>t[i];
        for(int i=1;i<=n;i++)
        {
            int nn,x,t1,y,t2;
            cin>>nn>>x>>t1>>y>>t2;
            mp[x][y]=mp[y][x]=min(t1+t2,mp[x][y]);
        }
        for(int k=1;k<=m;k++)
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(mp[i][j]>mp[i][k]+mp[k][j]) mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<mp[x][y]+t[x]+t[y]<<endl;
        }
    }
    return 0;
}
//by undercraft id=914813
//floyed?
