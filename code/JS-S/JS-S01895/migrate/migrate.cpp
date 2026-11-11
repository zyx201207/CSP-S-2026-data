#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll G[1005][1005];
ll n,d,a[2000005],cnt;
bool special_A;

bool BFS(ll start,ll to)
{
    queue<pair<ll,ll> >Q;
    Q.push({start,0});
    ll res=0;
    while(!Q.empty())
    {
        pair<ll,ll>u=Q.front();
        Q.pop();
        if(u.second==G[start][to]&&u.first==to)
            res++;
        if(u.second>G[start][to])
            continue;
        if(res>2)
            return false;
        for(int j=u.first+1;j<=to;j++)
        {
            if(a[j]-a[u.first]>d)
                break;
            Q.push({j,u.second+1});
        }
    }
    if(res==2)
        return true;
    return false;
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
            cin>>a[i];
        if(d==1)
        {
            cout<<"0\n";
            continue;
        }
        ll qwq=a[2]-a[1];
        for(int i=3;i<=n;i++)
            if(a[i]-a[i-1]!=qwq)
            {
                special_A=true;
                break;
            }
        cnt=0;
        memset(G,0x3f,sizeof G);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[j]-a[i]<=d)
                    G[i][j]=1;
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                for(int k=i+1;k<=j-1;k++)
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                if(BFS(i,j))
                    cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}
