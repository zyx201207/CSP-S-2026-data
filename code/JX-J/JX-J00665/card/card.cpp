#include <bits/stdc++.h>
using namespace std;
int n,m,a[500100],ans[200100],y[200100],game[500100],top;
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
        for(int j=1;j<=n;j++)
            y[j]=0;
        top=0;
        for(int j=i;j<=n;j++)
        {
            if(!y[a[j]])
            {
                game[++top]=a[j];
                y[a[j]]=top;
            }
            else
            {
                top=y[a[j]];
            }
        }
        for(int j=1;j<=top;j++)
        {
            ans[game[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
