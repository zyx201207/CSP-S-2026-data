#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001]={},ans[300001]={};
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
        bool flag[500001]={};
        int b[500001]={};
        for(int j=i;j<=n;j++)
        {
            if(flag[a[j]])
            {
                for(int k=b[a[j]];k<=j;k++)
                {
                    flag[a[k]]=false;
                    b[a[k]]=0;
                }
                flag[a[j]]=true;
                b[a[j]]=j;
            }
            else
            {
                flag[a[j]]=true;
                b[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==j)
            {
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
