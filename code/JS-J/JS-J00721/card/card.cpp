#include<bits/stdc++.h>
using namespace std;
const int M=300005;
const int N=500005;
int n,m,ans[M],b[M],a[N],w[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        w[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int k=j;k<=n;k++)
            {
                b[a[k]]=1;
                int p=w[a[k]];
                k=p;
            }
            if (b[i]==1)
                ans[i]++;
            for(int g=1;g<=m;g++)
            {
                b[g]=0;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
