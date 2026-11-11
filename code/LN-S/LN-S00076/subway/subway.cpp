#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e12;
int mn(int x,int y)
{
    if(x>y)
    {
        return y;
    }
    return x;
}
struct Node
{
    int dt;
    int pl;
};
struct Code
{
    int st;
    int en;
    int dt;
};
bool cmp(Code x,Code y)
{
    return x.dt<y.dt;
}
Node us;
int c,n,m,d,q;
int w[500005];
vector<Node> dot[500005];
vector<Code> edge;
Code dc;
int smaller[505][505];
int ans[505][505];
int ls[505][505];
void check(int is,int vs,int vy,int iy)
{
    if(ans[is][iy]>ans[is][vs]+ans[vs][vy]+ans[vy][iy])
    {
        ans[iy][is]=ans[is][iy]=ans[is][vs]+ans[vs][vy]+ans[vy][iy];
        for(int i=1;i<=n;i++)
        {
            if(ans[i][is]<inf)
                for(int j=1;j<=n;j++)
                {
                    check(i,is,iy,j);
                }
            if(ans[i][iy]<inf)
                for(int j=1;j<=n;j++)
                {
                    check(j,is,iy,i);
                }
        }
    }
    return;
}
void solve()
{
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int x,s1,s2;
        cin>>x;
        while(x--)
        {
            cin>>s1>>s2;
            us.dt=s2;
            us.pl=i;
            dot[s1].push_back(us);
        }
    }
    /*
    cout<<"/*"<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<dot[i].size();j++)
        {
            cout<<dot[i][j].pl<<","<<dot[i][j].dt<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans[i][j]=smaller[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans[i][i]=smaller[i][i]=0;
    }
    //cout<<"//"<<endl;
    for(int i=1;i<=m;i++)
    {
        //cout<<"size: "<<dot[i].size()<<endl;
        for(int j=0;j<dot[i].size();j++)
        {
            for(int k=0;k<j;k++)
            {
                int x=dot[i][j].pl;
                int y=dot[i][k].pl;
                int sum=dot[i][j].dt+dot[i][k].dt;
                //<<"i="<<i<<" j="<<j<<" k="<<k<<" x="<<x<<" y="<<y<<" sum="<<sum<<endl;
                smaller[x][y]=mn(smaller[x][y],sum);
                smaller[y][x]=mn(smaller[y][x],sum);
            }
        }
    }
    /*
    cout<<"//"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(int j=1;j<=n;j++)
        {
            if(smaller[i][j]==inf)
            {
                cout<<"% ";
            }
            else
            {
                cout<<smaller[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dc.st=i;
            dc.en=j;
            dc.dt=smaller[i][j];
            edge.push_back(dc);
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    for(int h=0;h<edge.size();h++)
    {
        int x=edge[h].st,y=edge[h].en;
        if(ans[x][y]>edge[h].dt)
        {
            ls[x][y]=ls[y][x]=h;
            ans[y][x]=ans[x][y]=edge[h].dt;
            for(int i=1;i<=n;i++)
            {
                if(ans[i][x]<inf)
                    for(int j=1;j<=n;j++)
                    {
                        check(i,x,y,j);
                    }
                if(ans[i][y]<inf)
                    for(int j=1;j<=n;j++)
                    {
                        check(j,x,y,i);
                    }
            }
        }
    }
    /*
    cout<<"//"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(int j=1;j<=n;j++)
        {
            if(ans[i][j]==inf)
            {
                cout<<"% ";
            }
            else
            {
                cout<<ans[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"/"<<endl;
    */
    //return;
    while(q--)
    {
        int s1,s2,gs,ge;
        cin>>s1>>s2;
        int output=inf;
        for(int i=0;i<dot[s1].size();i++)
        {
            for(int j=0;j<dot[s2].size();j++)
            {
                output=mn(output,ans[dot[s1][i].pl][dot[s2][j].pl]+dot[s1][i].dt+dot[s2][j].dt);
            }
        }
        cout<<output+w[s1]+w[s2]<<endl;
    }
    return;
}
signed main()
{
    //cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}


