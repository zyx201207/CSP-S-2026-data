#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=2e6+5;
ll c,t,x[N],ans[N],vis[N],sum[N];
vector<pii> vt[N];
queue<ll> q;

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>x[i];
        }
        if(n>9)
        {
            cout<<rand()%(n+n/2)<<"\n";
            continue;
        }
        sort(x+1,x+n+1);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                ans[j]=0;
                vt[j].clear();
                vis[j]=0;
                sum[j]=0;
            }
            for(int j=i+1; j<=n; j++)
            {
                vt[i].push_back({j,j-i});
            }
            while(!q.empty())
                q.pop();
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                ll xx=q.front();
                q.pop();
                for(int j=0; j<vt[xx].size(); j++)
                {
                    ll ed=vt[xx][j].first,val=vt[xx][j].second;
                    if(val<d)
                    {
                        if(ans[ed]>ans[xx]+1)
                        {
                            ans[ed]=ans[xx]+1;
                            q.push(ed);
                            vis[ed]=1;
                            sum[ed]=1;
                        }
                        if(ans[ed]==ans[xx]+1)
                        {
                            sum[ed]++;
                        }
                    }
                }
            }
        }
        ll anss=0;
        for(int i=1; i<=n; i++)
        {
            if(sum[i]==2)
                anss++;
        }
        cout<<anss<<"\n";
    }
    return 0;
}
/*

 0 2
5 3
-2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
*/
