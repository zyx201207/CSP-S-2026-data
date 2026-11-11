#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],l[300005],g[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[a[i]]+=i;
    }
    int cnt=1;
    for (int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        for (int j=i;j<=n;j++)
        {
            if (b[a[j]]==1)
            {
                l[a[j]]--;
                for (int k=cnt;g[k]!=a[j];k--)
                {
                    b[g[k]]=0;
                    l[g[k]]--;
                    g[k]=0;
                    cnt--;
                }
            }
            else
            {
                g[++cnt]=a[j];
                b[a[j]]++;
            }
        }
    }
    for (int i=1;i<=m;i++) cout<<l[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
