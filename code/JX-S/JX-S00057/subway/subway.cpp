#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int a[10005],tgs[10005],b[10005][10005];
    int jr[10005],cz[10005];
    int ans[10005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>tgs[i];
        for(int j=1;j<=tgs[i];j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>jr[i];
        cin>>cz[i];
    }
    for(int i=1;i<=q;i++)
    {
        ans[i]+=a[i];
        int js=1,zk=0,xl=0;
        while(zk!=cz[i])
        {
            if(js==1)
            {
                for(int j=1;j<=tgs[j]*2;j++)
                {
                    if(jr[i]==b[i][j] && j%2!=0)
                    {
                        ans[i]+=b[i][j+1];
                        zk=b[i][j];
                        xl=i;
                        js+=1;
                        break;
                    }
                }
            }
            else
            {
                while(zk!=cz[i])
                {
                    for(int k=1;k<=n;k++)
                    {
                        for(int j=1;j<=tgs[j]*2;j++)
                        {
                            if(zk==b[k+1][j] && k!=xl && j%2!=0 && zk!=cz[i])
                            {
                                ans[i]+=b[k+1][j+1];
                                zk=b[k+1][j];
                                break;
                            }
                            else
                                break;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[j]==cz[i])
                ans[i]+=a[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i];
    }
    return 0;
}
