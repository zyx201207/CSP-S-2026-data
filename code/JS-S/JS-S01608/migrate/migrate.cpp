#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

long long c,t,n,d,a[2000005],dp[205][205],minn,ans;
bool vis[205];
void dfs(int l,int r,int s)
{
    if(l==r)
    {
        if(s<minn)  minn=s,ans=1;
        else if(s==minn)    ans++;
    }
    for(int i=l+1;i<=r && a[i]-a[l]<=d;i++) dfs(i,r,s+1);
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)   cin>>a[i];
        long long cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=0,minn=INT_MAX;
                dfs(i,j,0);
                if(ans==2)  cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
