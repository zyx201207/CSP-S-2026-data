#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int op,n,m,d,q;
int w[M];
vector <int> a[N],t[N],s[M],st[M];
void solve1()
{
    int mp[1005][1005];
    memset(mp,-1,sizeof(mp));
    for(int i=1;i<=n;i++)
    for(int j=0;j<a[i].size();j++)
    for(int k=j+1;k<a[i].size();k++)
    {
        int x=a[i][j],y=a[i][k];
        int cost=t[i][j]+t[i][k];
        if(mp[x][y]==-1) mp[x][y]=mp[y][x]=cost;
        else if(mp[x][y]>cost) mp[x][y]=mp[y][x]=cost;
    }
    for(int k=1;k<=m;k++)
    for(int i=1;i<=m;i++)
    for(int j=i+1;j<=m;j++)
    if(mp[i][k]!=-1 && mp[j][k]!=-1)
    {
        if(mp[i][j]==-1) mp[i][j]=mp[j][i]=mp[i][k]+mp[j][k];
        else if(mp[i][k]+mp[j][k]<mp[i][j]) mp[i][j]=mp[j][i]=mp[i][k]+mp[j][k];
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<mp[x][y]+w[x]+w[y]<<"\n";
    }
}
void solve2()
{
    int mp[505][505];
    memset(mp,-1,sizeof(mp));
    for(int i=1;i<=n;i++) mp[i][i]=0;
    for(int i=1;i<=m;i++)
    for(int j=0;j<s[i].size();j++)
    for(int k=j+1;k<s[i].size();k++)
    {
        int x=s[i][j],y=s[i][k];
        mp[x][y]=mp[y][x]=1;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    if(mp[i][k]!=-1 && mp[j][k]!=-1)
    {
        if(mp[i][j]==-1) mp[i][j]=mp[j][i]=mp[i][k]+mp[j][k];
        else if(mp[i][j]>mp[i][k]+mp[j][k]) mp[i][j]=mp[j][i]=mp[i][k]+mp[j][k];
    }
    int T=t[1][0];
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y],res=n;
        for(int i=0;i<s[x].size();i++)
        for(int j=0;j<s[y].size();j++)
        if(mp[s[x][i]][s[y][j]]!=-1) res=min(res,mp[s[x][i]][s[y][j]]);
        cout<<ans+(res+1)*T*2<<"\n";
    }
}
void solve3()
{
    int cost=inf;
    for(int i=1;i<=m;i++)
    if(s[i].size()>1) cost=min(cost,st[i][0]+st[i][1]);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(s[x].size()==1 && s[y].size()==1 && s[x][0]!=s[y][0]) cout<<w[x]+w[y]+st[x][0]+st[y][0]+cost<<"\n";
        else if(s[x].size()==2 && s[y].size()==2) cout<<w[x]+w[y]+min(st[x][0]+st[y][0],st[x][1]+st[y][1])<<"\n";
        else if(s[x].size()==2)
        {
            if(s[y][0]==1) cout<<w[x]+w[y]+st[x][0]+st[y][0]<<"\n";
            else cout<<w[x]+w[y]+st[x][1]+st[y][0]<<"\n";
        }
        else
        {
            if(s[x][0]==1) cout<<w[x]+w[y]+st[x][0]+st[y][0]<<"\n";
            else cout<<w[x]+w[y]+st[x][0]+st[y][1]<<"\n";
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>op>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x),t[i].push_back(y);
            s[x].push_back(i),st[x].push_back(y);
        }
    }
    if(op<=11) solve1();
    else if(op<=19) solve2();
    else if(op<=21) solve3();
    return 0;
}
