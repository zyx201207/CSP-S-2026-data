#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[309];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            /*if(i>1&&x[i]-x[i-1]>d)
            {

            }*/
        }
        int ans=0;
        for(int u=1;u<=n;u++)
        {
            for(int v=u+1;v<=n;v++)
            {
                int t=(x[v]-x[u])/d;
                if((x[v]-x[u])%d!=0)
                {
                    t++;
                }
                int cnt=0;
                for(int k=u+1;k<v;k++)
                {
                    int w1=(x[k]-x[u])/d;
                    if((x[k]-x[u])%d!=0)
                    {
                        w1++;
                    }
                    int w2=(x[v]-x[k])/d;
                    if((x[v]-x[k])%d!=0)
                    {
                        w2++;
                    }
                    if(w1+w2==t)
                    {
                        cnt++;
                    }
                }
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
}
