#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,m,a[N],ans[N],pos[N];
int b[N],flag[N];

int main()
{
    freopen("card.in","r".stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int k=1;k<=n;k++)
    {
        int tot=0;
        for (int i=k;i<=n;i++)
        {
            int x=a[i];
            if (flag[x]==1)
            {
                for (int j=pos[x]+1;j<=tot;j++)
                    flag[b[j]]=0;
                tot=pos[x];
                continue;
            }
            b[++tot]=x;
            flag[x]=1;
            pos[x]=tot;
        }
        for (int i=1;i<=tot;i++)
        {
            flag[b[i]]=0;
            ans[b[i]]++;
        }
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
