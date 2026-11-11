#include<bits/stdc++.h>
using namespace std;
long long num[1000005],vis[1000005],sum[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         cin>>num[i];
         if(num[i]==num[i-1])
            vis[i-1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            cout<<i<<' ';
    }
    return 0;
}
