#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans;
int l[300005],w[300005],f[300005];
bool v[300005];

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)cin >>l[i];
    for(int d=1;d<=n;d++)
    {
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        for(int i=d;i<=n;i++)
        {
            if(w[l[i]]==0)w[l[i]]=i;
            else for(int j=w[l[i]];j<i;j++)v[j]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!v[i])f[l[i]]++;
        }
    }
    
    for(int i=1;i<=m;i++)printf("%lld ",f[i]);
}