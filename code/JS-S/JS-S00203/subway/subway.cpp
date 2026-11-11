#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5,N=505;
ll C,n,m,d,q,w[M],k[N];
vector<ll> a[N],t[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            ll u,v;
            cin>>u>>v;
            a[i].push_back(u);
            t[i].push_back(v);
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        ll ans;
        queue<pair<ll,ll>> que;
        que.push(make_pair(x,0));
        while(!que.empty())
        {
            pair<ll,ll>top=que.front();
            que.pop();
            if(top.first==y)
            {
                ans=top.second;
                break;
            }
            ll idx=0;
            for(ll u:a[top.first])
            {
                ll v=t[top.first][idx++];
                que.push(make_pair(u,v+top.second));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
