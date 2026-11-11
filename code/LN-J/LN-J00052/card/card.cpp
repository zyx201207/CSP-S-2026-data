#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[300005],a[500005],t1[300005],a1[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(t1,0,sizeof(t1));
        memset(a1,0,sizeof(a1));
        for(int j=i;j<=n;j++)
        {
            a1[j]=a[j];
            if(t1[a1[j]]==0)
            {
                t1[a1[j]]++;
                t[a1[j]]++;
            }
            else
            {
                t1[a1[j]]++;
                t[a1[j]]++;
                int f;
                for(int x=j-1;x>=1;x--)
                {
                    if(a1[x]==a1[j])
                    {
                        f=x;
                    }
                }
                for(int x=j-1;x>=f;x--)
                {
                    t[a1[x]]--,t1[a1[x]]--;
                    a1[x]=a1[x+1];
                    a1[x+1]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<t[i]<<' ';
    }
    return 0;
}
