#include <bits/stdc++.h>
using namespace std;
int dao[5005];
bool canget[5005][5005];
int que[5005],bushu[5005];
bool ifbeen[5005];
int first=10000;
int n,m;
bool bfs(int i,int k)
{
    first=100000;
    memset(que,0,sizeof(que));
    memset(bushu,0,sizeof(bushu));
    memset(ifbeen,0,sizeof(ifbeen));
    memset(bushu,0,sizeof(bushu));
    int tail=0;
    int head=1;
    que[0]=i;
    que[1]=0;
    int sum=0;
    while(tail<head)
    {
        for (int j=1;j<=n;j++)
        {
            //cout<<"try j = "<<j<<endl;
            if (canget[que[tail]][j]&&j!=que[tail])
            {
                ifbeen[j]=1;
                que[head]=j;
                bushu[head]=bushu[tail]+1;
                //cout<<"set bushu"<<bushu[tail]+1<<endl;
                head++;
                //cout<<"add"<<j<<endl;
                /*for (int t=0;t<head;t++)
                {
                    cout<<que[t]<<" ";
                }*/
                //cout<<endl;
                if (j==k)
                {
                    sum++;
                    if (sum==1)
                    {
                        first=bushu[head-1];
                    }
                    else
                    {
                        if (bushu[head-1]!=first)
                        {
                            if (sum==3)
                            {
                                //cout<<"add!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<i<<" "<<k<<endl;
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                    }
                    //cout<<"reach!! by "<<bushu[head-1]<<endl;
                }
            }
        }
        tail++;
        //cout<<"set tail"<<tail<<endl;
    }
    if (sum==2)
    {
        //cout<<"add!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<i<<" "<<k<<endl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int ans;
void calc()
{
    memset(dao,0,sizeof(dao));
    memset(canget,0,sizeof(canget));
    ans=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>dao[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (abs(dao[i]-dao[j])<=m)
            {
                canget[i][j]=1;
            }
            else
            {
                canget[i][j]=0;
            }
        }
    }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cout<<canget[i][j];
        }
        cout<<endl;
    }*/
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            //cout<<"now try"<<j<<" to  "<<i<<endl<<endl;
            if (bfs(j,i))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,T;
    cin>>a>>T;
    while(T--)
    {
        calc();
    }
}
