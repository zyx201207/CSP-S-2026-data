#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
ll a[N];
pair<int,int>dis[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;cin>>c>>T;
    while(T--)
    {
        int n;cin>>n;
        ll d;cin>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1) {cout<<"0\n";continue;}
        if(c>=11&&c<=12)
        {
            ll k=min((ll)n,d/(a[2]-a[1]));
            if(k<2) {cout<<"0\n";continue;}
            cout<<max(0ll,n-2*k+1)<<"\n";
            continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[j]={n+1,0};
            dis[i]={0,1};
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();q.pop();
                if(dis[u].second>2) continue;
                for(int v=u-1;a[u]-a[v]<=d&&v>=1;v--)
                    if(dis[v].first>dis[u].first+1) dis[v].first=dis[u].first+1,dis[v].second=dis[u].second,q.push(v);
                    else if(dis[v].first==dis[u].first+1) dis[v].second+=dis[u].second;
                for(int v=u+1;a[v]-a[u]<=d&&v<=n;v++)
                    if(dis[v].first>dis[u].first+1) dis[v].first=dis[u].first+1,dis[v].second=dis[u].second,q.push(v);
                    else if(dis[v].first==dis[u].first+1) dis[v].second+=dis[u].second;
            }
            // cerr<<i<<" ---\n";
            // for(int j=1;j<=n;j++)
            //     cout<<j<<" "<<dis[j].first<<" "<<dis[j].second<<"\n";
            for(int j=i+1;j<=n;j++)
                ans+=dis[j].second==2;
        }
        cout<<ans<<"\n";
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<"\n";
}