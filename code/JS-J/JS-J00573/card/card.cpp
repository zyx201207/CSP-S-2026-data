#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[500010];
int cnt[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        int c[5010],t[5010];int a[5010];
        for(int j=1;j<=5000;j++)
        {
            c[j]=0;
            t[j]=0;
            a[j]=v[j];
        }
        int s=0;
        for(int j=i;j<=n;j++)
        {
            if(t[a[j]]==0)
                t[a[j]]=j;
            else
            {
                a[t[a[j]]]=-1;
                t[a[j]]=j;
                a[j-1]=-2;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(a[j]==-1)
                s++;
            if(a[j]==-2)
            {
                s--;
                continue;
            }
            if(s<=0)
            {
                c[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++)
        {
            cnt[j]+=c[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
