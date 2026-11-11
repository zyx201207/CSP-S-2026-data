#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],sh[300001],y[300001];
void mj(int x,int bb)
{
    for(int i=bb-1;i>=1;i--)
    {
        y[a[i]]=0;
        if(a[i]==x) break;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(y,0,sizeof(y));
        for(int j=i;j<=n;j++)
        {
            if(y[a[j]]==0)
            {
                y[a[j]]=1;
            }
            else
            {
                mj(a[j],j);
                y[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++) sh[j]+=y[j];
    }
    for(int i=1;i<=m;i++) cout<<sh[i]<<" ";
    return 0;
}
