#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,n,k=0,al[N*3],fa[N*3];
ll d,x[N],b[N*3];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        int ans=0;
        k=0;
        memset(al,0,sizeof al);
        memset(fa,0,sizeof fa);
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
            b[++k]=x[i];
            b[++k]=x[i]-d;
            b[++k]=x[i]+d;
        }
        sort(b+1,b+k+1);
        k=unique(b+1,b+k+1)-b-1;
        for(int i=1;i<=n;i++)
        {
            int x_tr=lower_bound(b+1,b+k+1,x[i])-b;
            int fa1=lower_bound(b+1,b+k+1,x[i]-d)-b;
            int fa2=lower_bound(b+1,b+k+1,x[i]+d)-b;
            al[fa1]++;
            al[fa2]++;
            al[x_tr]++;
            fa[fa1]++;
            fa[fa2]++;
        }
        for(int i=1;i<=k;i++)
        {
            al[i]+=al[i-1];
            fa[i]+=fa[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            int l=lower_bound(b+1,b+k+1,x[i]+d)-b;
            for(int j=i+1;j<=n;j++)
            {
                int r=lower_bound(b+1,b+k+1,x[j]-d)-b;
                if((al[l]-al[r-1])-(fa[l]-fa[r-1])==2) ans++;
            }
        }
        printf("%d\n",ans);
        cout<<1;
    }
    return 0;
}
