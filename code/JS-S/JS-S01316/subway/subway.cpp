#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;
const int MAXM=2e4+10;
int c,n,m,d,q;
int exittime[MAXN];
int sn[MAXN];
int lint[MAXN][MAXM];
int maxt=0;
int flag[MAXN];
int huan[MAXN];
int dfs(int x,int y,int z)
{
    if(x==y)
    {
        return -1;
    }
    int ans=maxt,ln=0;
    flag[x]=1;
    for(int i=1;i<=n;i++)
    {

        if(lint[x][i]!=0)
        {
            for(int j=1;j<=m;j++)
            {
                if(lint[j][i]!=0&&j==y)
                {
                    ans=0;
                    if(i!=z&&z!=0)
                    {
                        ans=lint[x][ln]+lint[j][ln];
                    }
                    if(i!=z&&z==0)
                    {
                        ans=0;
                    }
                    return ans;
                }
                if(lint[j][i]!=0&&flag[j]==0&&huan[j]>1)
                {
                    if(z==0)
                    {
                        z=i;
                    }
                    int t=min(ans,dfs(j,y,z));
                    if(t==-1)
                    {
                        ln=i;
                        if(ln!=z&&z!=0)
                        {
                            ans=lint[x][ln]+lint[j][ln];
                        }
                        break;

                    }
                    else if(ans>t)
                    {
                        ans=t;
                        ln=i;
                        if(ln!=z&&z!=0)
                        {
                            ans+=lint[x][ln]+lint[j][ln];
                        }
                    }
                }
            }

        }

    }

    flag[x]=0;
    return ans;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>exittime[i];
        maxt=max(maxt,exittime[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int chuan=0;
        cin>>chuan;
        sn[i]=chuan;
        for(int j=1;j<=chuan;j++)
        {
            int aij,tij;
            cin>>aij>>tij;
            lint[aij][i]=tij;
            huan[aij]++;
            maxt=max(maxt,tij);

        }
    }
    //for(int i=1;i<=n;i++)
    //{
    //    for(int j=1;j<=m;j++)
    //    {
    //
    //        cout<<lint[j][i]<<' ';
    //    }
    //    cout<<endl;
    //}
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y,0)+exittime[x]+exittime[y]<<"\n";
    }
    return 0;
}
