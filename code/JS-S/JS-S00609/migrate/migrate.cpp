#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN=2e6+10;
int c,t;
int n,d;
int x[MAXN];
int ans;
bool used[MAXN];
int cnt;
int mn;
void dfs(int l,int r,int dep)
{
    if(dep==r)
    {
        int len=0;
        int lst=x[l];
        for(int i=l+1;i<=r;i++)
        {
            if(x[i]-lst<=d&&used[i]==true)
            {
                len++;
                lst=x[i];
            }
            else if(x[i]-lst>d&&used[i]==true)
            {
                return;
            }
        }
        if(len<mn)
        {
            mn=len;
            cnt=1;
        }
        else if(len==mn)
        {
            cnt++;
        }
        return;
    }
    for(int i=0;i<=1;i++)
    {
        used[dep]=i;
        dfs(l,r,dep+1);
    }
}
void solve()
{
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+2;j<=n;j++)
        {
            cnt=0;
            mn=INF;
            for(int x=i;x<=j;x++)
            {
                used[x]=false;
            }
            used[i]=used[j]=true;
            dfs(i,j,i+1);
            if(cnt==2)
            {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}