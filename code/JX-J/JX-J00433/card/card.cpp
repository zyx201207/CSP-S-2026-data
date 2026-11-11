#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N],q[N],cnt[N],w[N];
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        w[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        memset(q,0,sizeof(q));
        for(int j=i;j<=n;j++)
        {
            if(w[a[j]]>1)
            {
                int s=j;
                for(int o=s;o>=1;o--)
                    q[o]=0;
            }
            q[j]=a[j];
        }
        for(int u=1;u<=n;u++)
            if(q[u]!=0)
                cnt[i]++;
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<endl;
    return 0;
}
