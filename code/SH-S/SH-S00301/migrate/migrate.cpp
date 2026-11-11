#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],ans[2000005],m[2000005];
void dfs(ll s,ll now)
{
    for(int i = now+1;i <= n;++i)
    {
        if(x[i]-x[now]<=d)
        {
            if(s<m[i])
            {
                m[i]=s;
                ans[i]=1;
            }
            else if(s==m[i])
            {
                ans[i]++;
            }
            dfs(s+1,i);
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ll cnt=0;
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(int i = 1;i <= n;++i) cin>>x[i];
        for(int i = 1;i < n;++i)
        {
            memset(ans,0,sizeof(ans));
            for(int i = 1;i <= n;++i) m[i]=2e18;
            dfs(1,i);
            for(int j = i+1;j <= n;++j)
            {
                if(ans[j]==2) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
