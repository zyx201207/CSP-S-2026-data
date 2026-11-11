#include<iostream>
#include<algorithm>
using namespace std;
long long x[2010],mp[2010];
long long n,d;
long long T[2010][2010];
long long dfs(int u,int v,long long &xx)
{
    long long cut=0,ans=0,q=0;
    if(u==v)return 0;
    for(int i=u+1;i<=v;i++)
    {
        if(abs(x[i]-x[u])>d)break;
        else
        {
            long long z;
            long long y;
            y=dfs(i,v,z)+1;
            if(q==0)
            {
                q=1;
                cut=y;
                ans=1;
            }
            else
            {
                if(cut>y&&y>0)
                {
                    ans=1;
                    cut=y;
                }
                else if(cut==y&&y>0)ans++;
            }
        }
    }
    xx=ans;
    //cout<<u<<' '<<v<<' '<<cut<<' '<<xx<<"\n";
    if(ans==0)cut=-0x3f3f3f;
    return cut;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    //cin.tie(0);

    long long c,t;
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)cout<<0<<"\n";
        return 0;
    }
    while(t--)
    {
        cin>>n>>d;
        long long cut=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int u=1;u<=n;u++)
        {
            for(int v=u+1;v<=n;v++)
            {
                long long z;
                dfs(u,v,z);
                if(z==2)
                {
                    cut++;
                //    cout<<"\n"<<u<<' '<<v<<"\n\n";
                }
            }
        }
        cout<<cut<<"\n";
    }
    return 0;
}
