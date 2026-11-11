#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(x,0ll,sizeof(x));
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int u=1;u<=n-3;u++)
        {
            for(int v=u+3;v<=n;v++)
            {
                int sum=0;
                for(int j=u+1;j<v;j++)
                {
                    if(x[j]-x[u]<=d&&x[v]-x[j]<=d)
                        sum++;
                }
                if(sum==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
