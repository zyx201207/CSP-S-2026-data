#include<bits/stdc++.h>
using namespace std;
const int MAXN =5050;
typedef long long ll;
ll a[MAXN],c,t,n,d,dis[MAXN][MAXN],s[MAXN][MAXN];
void dfs(ll st,ll fi,ll no,ll ti)
{
    if(ti>=dis[st][fi]) return;
    if(a[fi]-a[no]<=d)
    {
        if(dis[st][fi]==ti+1) s[st][fi]++;
        if(dis[st][fi]>ti+1)
        {
            dis[st][fi]=ti+1;
            s[st][fi]=1;
        }
        return;
    }
    for(ll i=no+1;i<=fi;i++)
    {
        if(a[i]-a[no]>d) return;
        dfs(st,fi,i,ti+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                dis[i][j]=LLONG_MAX;
                s[i][j]=0;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dfs(i,j,i,0);
            }
            
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[i][j]==2)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}