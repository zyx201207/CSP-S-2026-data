#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[500010],d[5010],mmp[5010];
int mp[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,q=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])q=0;
    }
    if(q)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1])mp[a[i]]+=1;
            else mp[a[i]]+=i;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<mp[i]<<' ';
        }
    }
    else{
        for(int i=1;i<=n;i++)
        {
            for(int i=1;i<=5000;i++)d[i]=0;
            for(int i=1;i<=5000;i++)mmp[i]=0;
            int fd=0;
            for(int j=i;j<=n;j++)
            {
                if(mmp[a[j]]==0)
                {
                    d[++fd]=a[j];
                    mmp[a[j]]=1;
                }
                else{
                    while(d[fd]!=a[j])
                    {
                        mmp[d[fd]]=0;
                        fd--;
                    }
                    d[++fd]=a[j];
                    mmp[a[j]]=1;
                }
            }
            for(int i=1;i<=m;i++)mp[i]+=mmp[i];
        }
        for(int i=1;i<=m;i++)
        {
            cout<<mp[i]<<' ';
        }
    }
    return 0;
}
