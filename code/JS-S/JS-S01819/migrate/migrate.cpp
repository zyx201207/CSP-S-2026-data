#include<bits/stdc++.h>
using namespace std;
int c,t,n,minn;
long long d,x[2000001],a[2000001],l,ans;
void dfs(int s,int e,int de)
{
    if(s==e&&de<=minn)
    {
        if(de<minn)
        {
            minn=de;
            l=1;
        }
        else
        {
            l++;
        }
    }
    for(int i=s+1;i<=e;i++)
    {
        if(x[i]-d-x[s]<=0)
        {
            dfs(i,e,de+1);
        }
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
    {
        long long g,h;
        for(int i0=0;i0<t;i0++)
        {
            cin>>n>>d;
            ans=0;
            for(int j=1;j<=n;j++)
            {
                cin>>x[j];
            }
            g=x[2]-x[1];
            h=d/g;
            if(h<2)
            {
                cout<<0<<endl;
            }
            else
            {
                ans+=max(n-h*2+1,(long long)0);
                cout<<ans<<endl;
            }

        }
    }
    else
    {
        for(int i0=0;i0<t;i0++)
        {
            cin>>n>>d;
            for(int j=1;j<=n;j++)
            {
                cin>>x[j];
            }
            ans=0;
            for(int i=1;i<=n-3;i++)
            {
                for(int j=i+3;j<=n;j++)
                {
                    l=0;
                    minn=n;
                    dfs(i,j,0);
                    if(l==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
