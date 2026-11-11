#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt;
const int maxn=100010101;
int u[maxn],v[maxn];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    int sum=0;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
           cin>>u[i]>>v[i];
        }
        break;
    }
    int changdu=sum-1;
    for(int i=0;i<=changdu/2;i++)
    {
        int f=changdu-i;

        if(u[i]!=v[f])
        {
            cnt++;
        }
    }
    cout<<1<<endl;
    cout<<cnt+2;
    return 0;
}
