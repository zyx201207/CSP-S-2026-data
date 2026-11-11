#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005];
vector<long long>g[2000005];
int ans=INT_MAX-1,cs;
void dfs(int u,int mb,int fa,int bs)
{
    if(u==mb){if(bs<ans){ans=bs;cs=1;return;}else if(bs==ans){cs++;return;}}
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,mb,fa,bs+1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            int kkk=i-1;
            while(kkk>=1&&x[i]-x[kkk]<=d){g[kkk].push_back(i);kkk--;}
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=INT_MAX-1;cs=0;
                dfs(i,j,0,0);
                if(cs==2) sum++;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
