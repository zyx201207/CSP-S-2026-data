#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005],n,m;
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int sta[500005]={0},top=0,p[300005];
        for(int j=1;j<=m;j++)p[i]=-1;
        for(int j=i;j<=n;j++)
        {
            if(p[a[j]]==-1)
            {
                sta[++top]=a[j];
                p[a[j]]=top;
            }
            else
            {
                top=p[a[j]];
            }
        }
        for(int j=top;j>=1;j--)
        ans[sta[j]]++;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    return 0;
}
