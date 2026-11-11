#include <bits/stdc++.h>
using namespace std;
int n,k;
int c,t;
const int N=5e5+5;
vector<int> e[N];
int she[N];
bool vis[N];
void solve()
{
    cin>>n>>k;
    bool ok=true;
    for(int i=1;i<=n;i++)
    {
        e[i].clear();
        she[i]=0;
        vis[i]=false;
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
        she[a]++;
        she[b]++;
        if(i<=n/2&&(a!=i||b!=i+1))
        {
            ok=false;
        }
        else if(i>n/2&&(a!=(i-n/2)||b!=i+1))
        {
            ok=false;
        }
    }
    if(ok)
    {
        int m=n/2+4-k;
        cout<<m/4+1<<"\n";
        return;
    }
    else
    {
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(she[i]==1)
            {
                s=i;
                break;
            }
        }
        queue<int> q;
        q.push(s);
        vis[s]=true;
        int ans=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:e[u])
            {
                if(!vis[v])
                {
                    vis[v]=true;
                    she[v]=she[u]+1;
                    ans=max(she[v],ans);
                    q.push(v);
                }
            }
        }
        if((ans-k+1)%4==0)
        {
            cout<<(ans-k+1)/4<<"\n";
        }
        else cout<<(ans-k+1)/4+1<<"\n";
        return;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}
