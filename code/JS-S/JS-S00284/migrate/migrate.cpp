#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXL=2000005;
int n,d;
int c,T;
int x[MAXL];
int get_l(int w)
{
    int s=0;
    int i=w+1;
    while(i<n-1&&x[i]<=x[w]+d&&x[i]>=x[i+1]-d&&x[w+1]<=x[w]+d&&x[w+1]>=x[i+1]-d)
    {
        i++;
        s++;
    }
    return s;
}
int find_single(int w)
{
    int s=0;
    int i=w+1;
    while(x[i]-x[i-1]<=d&&(i==1||x[i]-x[i-2]>d))
    {
        i++,s++;
    }
    return s;
}
int work()
{
    scanf("%lld %lld",&n,&d);
    for(int i=0;i<n;i++)
    {
        scanf("%lld ",&x[i]);
    }
    if(c==11||c==12)
    {
        if(x[2]-x[0]>d)
        {
            return 0;
        }
        else
        {
            int ans=0;
            int w=0;
            while(x[w]-x[0]<=d)
            {
                w++;
            }
            for(int i=3;i<=w;i++)
            {
                ans+=n-i;
            }
            return ans;
        }
    }
    int ans=0;
    int single_length=0;

    for(int i=0;i<n;i++)
    {
        int t=get_l(i);
        int i1=i+t+1;
        int te=find_single(i1);
        if(t==2)
        {
            ans+=te+1;
        }
        if(t>2)
        {
            ans+=te+1;
        }
        i=i1+te;
    }
    return ans;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%lld %lld",&c,&T);
    while(T--)
    {
        //cin>>n>>d;
        n=d=0;
        memset(x,0,sizeof(x));
        printf("%lld\n",work());
    }
}
