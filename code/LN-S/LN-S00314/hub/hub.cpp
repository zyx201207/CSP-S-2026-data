#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }
        printf("%d\n",(n-k)/3);
    }
    return 0;
}
