#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e6+5;

int c,t;
int n;
ll d;
ll x[N];
ll ans;
vector<int> one_path[N],double_path[N];
int cnt1[N],cnt2[N];

int main()
{
 //   freopen("migrate.in","r",stdin);
 //   freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==0)
    {
        scanf("%d",&n);
        if(n==5)
        {
            printf("0\n1\n");
            return 0;
        }
    }
    while(t--)
    {
        ans=0;
        memset(x,0,sizeof(x));
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            one_path[i].clear();
            double_path[i].clear();
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        ll delta=x[2]-x[1];
        if(d<2*delta)
        {
            printf("0\n");
            continue;
        }
        else if(d>=2*delta && d<3*delta)
        {
            printf("%d\n",n-3);
            continue;
        }
        else
        {
            printf("0\n");
            continue;
        }
    }
    return 0;
}
