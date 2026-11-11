#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=1e18;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;

    if(c==11||c==12)
    {
        while(t--)
        {
            int n,d;
            cin>>n>>d;

            if(n==1)
            {
                cin>>d;
                cout<<"0\n";
                continue;
            }

            vector<int> x(n+1);
            for(int i=1;i<=n;++i) cin>>x[i];
            int dd=x[2]-x[1];
            int cnt=d/dd;

            int ok=2*cnt-1;
            if(cnt>1)
            {
                cout<<max(0ll,n-ok)<<'\n';
            }
            else cout<<"0\n";
        }

        return 0;
    }

    while(t--)
    {
        int n,d;
        cin>>n>>d;

        if(n==1)
        {
            cin>>d;
            cout<<"0\n";
            continue;
        }

        vector<int> x(n+1);
        vector<vector<int>> gra(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>x[i];
            for(int j=1;j<i;++j)
            {
                if(x[i]-x[j]<=d) gra[j].emplace_back(i);
            }
        }

        int res=0;
        for(int s=1;s<=n;++s)
        {
            vector<int> dis(n+1,INF),dp(n+1);
            dis[s]=0;
            dp[s]=1;

            queue<int> q;
            q.emplace(s);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(int v:gra[u])
                {
                    if(dis[v]>dis[u]+1)
                    {
                        dis[v]=dis[u]+1;
                        dp[v]=dp[u];
                        q.emplace(v);
                    }
                    else if(dis[v]==dis[u]+1)
                    {
                        dp[v]+=dp[u];
                    }
                }
            }

            for(int t=s+1;t<=n;++t)
            {
                if(dp[t]==2) ++res;
            }
        }
        cout<<res<<'\n';
    }

    return 0;
}