#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5005;

int n,d;
int a[N];
vector<int> G[N];
void add(int u,int v)
{G[u].push_back(v);}
int dis[N],cnt[N];

void bfs(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[s]=0,cnt[s]=1;
    for(int u=s;u<=n;u++)
    {
        for(auto v:G[u])
        {
            if(dis[v]>dis[u]+1)
                dis[v]=dis[u]+1,cnt[v]=cnt[u];
            else if(dis[v]==dis[u]+1)
                cnt[v]+=cnt[u];
        }
    }
    return ;
}

void solve()
{
    cin>>n>>d;
    for(int i=0;i<=n+1;i++)
        a[i]=dis[i]=cnt[i]=0,G[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=n;j>=i;j--)
            if(cnt<3&&a[j]-a[i]<=d)
                add(i,j),cnt++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        for(int j=i+1;j<=n;j++)
        {
            if(cnt[j]==2)
            {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    return ;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,t;cin>>c>>t;while(t--){solve();}
    return 0;
}

/*
 wo shi sha bi 
 2.5h xie le yi tuo zhe ge 
 chun zai shui jiao

#include<bits/stdc++.h>
#define int long long
#define dg(x) #x<<':'<<(x)<<' '
using namespace std;

const int N=2e6+5;

int n,d;
int a[N];
vector<int> tr1[N],tr2[N];
void add(int u,int v,vector<int> (&tr)[N])
{tr[u].push_back(v);}
int sz1[N],sz2[N];
int l[N],r[N];

void dfs(int u,vector<int> (&tr)[N],int (&sz)[N])
{
    sz[u]=1;
    for(auto v:tr[u])
        dfs(v,tr,sz),sz[u]+=sz[v];
    return ;
}

int calc(int i,vector<int> (&tr)[N],int (&sz)[N],int opt)
{
    int res=0;
    for(auto v:tr[i])
    {
        if(v==i-1) continue;
        if(abs(a[i+opt]-a[v])>d) continue;
        res+=sz[v];
    }
    return res;
}

void print(int u,vector<int> (&tr)[N],int(&sz)[N],int fa=0)
{
    if(fa==0) cout<<"rt ";
    else cout<<"fa: "<<fa<<' ';
    cout<<dg(u)<<dg(sz[u])<<'\n';
    for(auto v:tr[u])
        print(v,tr,sz,u);
    return ;
}

void solve()
{
    cin>>n>>d;
    for(int i=0;i<=n+1;i++)
        a[i]=l[i]=r[i]=sz1[i]=sz2[i]=0,
        tr1[i].clear(),tr2[i].clear();
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<i&&a[i]-a[j]>d)
            j++;
        l[i]=j;
        if(i!=j)
            add(j,i,tr2);
    }
    for(int i=n,j=n;i>=1;i--)
    {
        while(i<j&&a[j]-a[i]>d)
            j--;
        r[i]=j;
        if(i!=j)
            add(j,i,tr1);
    }
    for(int i=1;i<=n;i++)
        cout<<l[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++)
        cout<<r[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++)
    {
        if(r[i]==i)
            dfs(i,tr1,sz1);
            // print(i,tr1,sz1);
    }

    for(int i=1;i<=n;i++)
    {
        if(l[i]==i)
            dfs(i,tr2,sz2);
            // print(i,tr2,sz2);
    }
    int ans=0;
    for(int i=2;i<=n-2;i++)
    {
        int a=calc(i+1,tr1,sz1,-1),
            b=calc(i  ,tr2,sz2, 1);
        cout<<dg(i)<<dg(a)<<dg(b)<<'\n';
        ans+=(a*b);
    }
    cout<<ans<<'\n';
    return ;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,t;cin>>c>>t;while(t--){solve();}
    return 0;
}
*/