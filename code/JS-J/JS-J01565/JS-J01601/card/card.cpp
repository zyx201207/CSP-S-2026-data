#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int h[N],a[N],n,m,t,ans[N];
bool b[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        memset(h,0,sizeof(h));
        memset(b,0,sizeof(b));
        int j=i;
        for(j=i;j<=n;j++) h[a[j]]++;
        j=i;
        while(1)
        {
            if(j>n) break;
            b[a[j]]=1;
            if(h[a[j]]>1)
            {
                t=a[j];
                while(1)
                {
                    j++;
                    if(a[j]==t) break;
                    h[a[j]]--;
                }
                h[t]--;
                j--;
            }
            j++;
        }
        for(int i=1;i<=m;i++) ans[i]+=b[i];
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}
