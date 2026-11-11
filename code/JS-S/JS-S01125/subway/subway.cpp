#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int tim[100][100];
struct station{
vector<int> v;
vector<int> val;
int w;
}sta[1000];
void add(int a,int b,int i)
{
    sta[a].v.push_back(b),sta[a].val.push_back(tim[i][a]+tim[i][b]);
    sta[b].v.push_back(a),sta[b].val.push_back(tim[i][b]+tim[i][a]);
}
int search(int s,int e)
{
    int dp[100][100]={0};
    bool v[1000];
    memset(dp,0x7f,sizeof(dp));
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<=sta[x].v.size();i++)
        {
            dp[x][sta[x].v[i]]=min(dp[s][x]+sta[x].val[i],dp[x][sta[x].v[i]]);
        }

    }
    return dp[s][e];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

        for(int i=1;i<=m;i++)
        {
            cin>>sta[i].w;
        }
        for(int i=1;i<=n;i++)
        {
            int k;
            int a[1000];
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                int t;
                cin>>a[j]>>t;
                tim[i][a[j]]=t;
            }
            for(int j=1;j<=k;j++)
                for(int l=1;l<=k;j++)
                {
                    if(j!=l)add(a[j],a[l],i);
                }
        }
    for(int i=1;i<=q;i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<search(s,e);
    }

    return 0;
}
