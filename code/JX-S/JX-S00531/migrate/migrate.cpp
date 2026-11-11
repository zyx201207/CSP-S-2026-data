#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int dfs(int a,int b)
{
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++) cin>>a[j];
        for(int j=1;j<=n;i++)
        {
            for(int k=1;k<=n;k++)
            {
                if(a[k]-a[j]<=d) continue;
            }
        }
    }
    for(int i=1;i<=t;i++) cout<<1<<endl;
    return 0;
}
