#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,k;
ll a[1005],ans;
vector<ll>G[1005];

bool check()
{
    bool b[1005]={};
    queue<ll>Q;
    for(int i=1;i<=n;i++)
        if(a[i]==1)
        {
            Q.push(i);
            break;
        }
    while(!Q.empty())
    {
        ll u=Q.front();
        Q.pop();
        if(a[u]==0)
            continue;
        b[u]=1;
        for(ll v:G[u])
            if(a[v]==1&&b[v]==0)
                Q.push(v);
    }
    for(int i=1;i<=n;i++)
        if(a[i]==1&&b[i]==0)
        {
            Q.push(i);
            break;
        }
    while(!Q.empty())
    {
        ll u=Q.front();
        Q.pop();
        if(a[u]==0||b[u]==1)
            continue;
        b[u]=1;
        for(ll v:G[u])
            if(a[v]==1&&b[v]==0)
                Q.push(v);
    }
    for(int i=1;i<=n;i++)
        if(a[i]==1&&b[i]==0)
            return false;
    return true;
}

ll fun()
{
    ll res2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
            continue;
        queue<pair<ll,ll> >Q;
        Q.push({i,0});
        ll res=1e8;
        bool b[1005]={};
        while(!Q.empty())
        {
            pair<ll,ll>u=Q.front();
            Q.pop();
            if(b[u.first]==1)
                continue;
            b[u.first]=1;
            if(a[u.first]==1)
            {
                res=min(res,u.second);
            }
            for(ll v:G[u.first])
                if(b[v]==0)
                    Q.push({v,1+u.second});
        }
        res2=max(res2,res);
    }
    return res2;
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=1000;i++)
            G[i].erase(G[i].begin(),G[i].end());
        for(int i=1,x,y;i<=n;i++)
        {
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        cout<<++ans<<"\n";
    }
    return 0;
}
