#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+5;
int c;
ll a[MAXN];
ll dp[MAXN];

vector<int>v[MAXN];
ll mi=LLONG_MAX;
ll cnt=0;

void dfs(int x,int y,int step)
{
    if(step>mi)return;
    if(x>y)return;
    if(x==y)
    {
        if(step<mi)
        {
            mi=step;
            cnt=1;
        }
        else if(step==mi)
        {
            cnt++;
        }
        return;
    }
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i],y,step+1);
    }
}
void sol()
{
    int ans=0;
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]-a[i]>d)break;
            v[i].push_back(j);
        }
    }
    bool B=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()==n-1)
        {
            B=1;
            break;
        }
    }
    if(B)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                cnt=0;
                mi=2;
                dfs(i,j,0);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    bool C=0;
    if(a[n]-a[1]<10*d)C=1;
    if(C)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                cnt=0;
                mi=10;
                dfs(i,j,0);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            cnt=0;
            mi=LLONG_MAX;
            dfs(i,j,0);
            if(cnt==2)ans++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T=1;cin>>c>>T;
    while(T--)sol();
    return 0;
}
