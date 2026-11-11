#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,tot,minn;
long long d,x[N];
void dfs(int step,int e,int cnt)
{
    if (step==e)
    {
        if (cnt<minn)
        {
            minn=cnt;
            tot=1;
        }
        else if (cnt==minn)
            tot++;
        return;
    }
    if (step>e)
        return;
    int i=step+1;
    while (x[i]-x[step]<=d)
        dfs(i,e,cnt+1);
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--)
    {
        int n;
        long long ans=0,f=0;
        bool v=true;
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>x[i];
            if (f!=0&&x[i]-x[i-1]!=ans)
                f=v=false;
            if (i>1)
                ans=x[i]-x[i-1];
        }
        if (v)
        {
            if (d<2*f)
                cout<<0<<"\n";
            else
                cout<<n-d/f-1<<"\n";
            continue;
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                minn=2e9;
                dfs(i,j,0);
                if (tot==2)
                    ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
