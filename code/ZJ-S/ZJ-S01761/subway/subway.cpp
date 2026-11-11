#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int a,b,id,ans;
}s[100005];
vector<pair<int,int> >v[500005];
vector<int>v1[20005],v2[20005];
map<pair<int,int>,int>mp;
bool vis[500005];
int c,n,m,d,q,w[500005],xx[500005],yy[500005],di[500005];
int a[500005][3];
bool cmp(node x,node y)
{
    return x.a<y.a;
}
bool cmp1(node x,node y)
{
    return x.id<y.id;
}
void dij(int st)
{
    priority_queue<pair<int,int> >pq;
    for(int i=1;i<=m;i++) di[i]=1e18,vis[i]=0;
    di[st]=0;
    pq.push({0,st});
    while(!pq.empty())
    {
        int x=pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(pair<int,int> i:v[x])
        {
            int y=i.first,z=i.second;
            if(di[y]>di[x]+z)
            {
                di[y]=di[x]+z;
                pq.push({-di[y],y});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c<=11)
    {
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++) cin>>xx[j]>>yy[j];
            for(int j=1;j<=k;j++)
                for(int l=j+1;l<=k;l++)
                {
                    if(mp[{xx[j],xx[l]}]) mp[{xx[j],xx[l]}]=mp[{xx[l],xx[j]}]=min(mp[{xx[j],xx[l]}],yy[j]+yy[l]);
                    else mp[{xx[j],xx[l]}]=mp[{xx[l],xx[j]}]=yy[j]+yy[l];
                }
        }
        for(int i=1;i<=m;i++)
            for(int j=i+1;j<=m;j++)
            {
                if(mp.find({i,j})!=mp.end())
                {
                    v[i].push_back({j,mp[{i,j}]});
                    v[j].push_back({i,mp[{i,j}]});
                }
            }
        for(int i=1;i<=q;i++) cin>>s[i].a>>s[i].b,s[i].id=i;
        sort(s+1,s+q+1,cmp);
        for(int i=1;i<=q;i++)
        {
            if(s[i].a!=s[i-1].a) dij(s[i].a);
            s[i].ans=di[s[i].b];
        }
        sort(s+1,s+q+1,cmp1);
        for(int i=1;i<=q;i++) cout<<s[i].ans+w[s[i].a]+w[s[i].b]<<"\n";
        return 0;
    }
    if(12<=c&&c<=19)
    {
        int T;
        for(int i=1;i<=n;i++)
        {
            int k,x;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>x>>T;
                v1[i].push_back(x);
                v2[x].push_back(i);
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            queue<int>Q;
            for(int i=1;i<=m;i++) vis[i]=0,di[i]=1e18;
            for(int i:v2[x])
                for(int j:v1[i])
                {
                    if(j==x||vis[j]) continue;
                    Q.push(j);
                    if(j==y) di[j]=0;
                    else di[j]=1;
                    vis[j]=1;
                }
            while(!Q.empty())
            {
                int xx=Q.front();
                Q.pop();
                if(xx==y) break;
                for(int i:v2[xx])
                    for(int j:v1[i])
                    {
                        if(vis[j]) continue;
                        Q.push(j);
                        di[j]=di[xx]+1;
                        vis[j]=1;
                    }
            }
            cout<<w[x]+w[y]+di[y]*2<<"\n";
        }
    }
    if(c==20||c==21)
    {
        int mi=1e18,id=0;
        for(int i=1;i<=n;i++)
        {
            int k,x,y;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                cin>>x>>y;
                a[x][i]=y;
                if(i==2&&a[x][1])
                {
                    if(a[x][1]+a[x][2]<mi) mi=a[x][1]+a[x][2],id=x;
                }
            }
        }
        while(q--)
        {
            int x,y,ans=1e18;
            cin>>x>>y;
            if(a[x][1]&&a[y][1]) ans=min(ans,a[x][1]+a[y][1]+w[x]+w[y]);
            if(a[x][2]&&a[y][2]) ans=min(ans,a[x][2]+a[y][2]+w[x]+w[y]);
            if(a[x][1]&&a[y][2])
            {
                if(id!=x&&id!=y) ans=min(ans,a[x][1]+a[y][2]+mi+w[x]+w[y]);
            }
            if(a[x][2]&&a[y][1])
            {
                if(id!=x&&id!=y) ans=min(ans,a[x][2]+a[y][1]+mi+w[x]+w[y]);
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    //if(c==22||c==23)
    //{

    //}
    return 0;
}
