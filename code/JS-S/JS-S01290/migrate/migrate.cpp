#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll a[2000006];
ll cnt[2000006];
ll b[2000006];
void dfs(int x,int step)
{
    if(b[x]>step)
    {
        b[x]=step;
        cnt[x]=1;
    }
    else if(b[x]==step)
    {
        cnt[x]++;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(a[i]-a[x]<=d)
        {
            dfs(i,step+1);
        }
        else
            return;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            {
                cin>>a[i];
                b[i]=INT_MAX;
                cnt[i]=0;
            }
            int ans=0;
        for(int i=1;i<=n;i++)
        {
            dfs(i,0);
            for(int j=i+1;j<=n;j++)
        {
            if(cnt[j]==2)
                ans++;
                cnt[j]=0;
        }
        }


        cout<<ans<<endl;
    }
}
