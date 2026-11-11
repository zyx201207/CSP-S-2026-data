#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
void solve1()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
    }
    int ans=(((n/k)-1)>>1);
    while(k*(ans*2+1)<n) ans++;
    printf("%d\n",ans);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==13 or c==14)
    {
        while(t--)
        {
            solve1();
        }
    }
    return 0;
}
