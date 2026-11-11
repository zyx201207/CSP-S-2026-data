#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005];
struct node
{
    int v,x;
};
struct qn
{
    int v;int x;
    //int t;
};
struct cmp
{
    bool operator()(qn a,qn b)
    {
        return a.v>b.v;
    }
};
map<int,vector<node> > edge;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int last=-1;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            edge[a].push_back({t,i*m+a});
            edge[i*m+a].push_back({t,a});
            if(last!=-1)
            {
                edge[i*m+a].push_back({0,last});
                edge[last].push_back({0,i*m+a});
            }
            last=i*m+a;
        }
    }
    /*
    for(int i=1;i<=m*m+m;i++)
    {
        for(auto xx:edge[i])
        {
            cout<<xx.x<<" "<<xx.v<<"   ";
        }
        cout<<"\n";
    }
    */
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;

        priority_queue<qn,vector<qn>,cmp> q;
        q.push({w[x],x/*,x*/});
        map<int,int> v;
        //v[x]=1;
        while(!q.empty())
        {
            auto h=q.top();q.pop();
            if(h.x==y)
            {
                cout<</*h.t<<" "<<*/h.v+w[y]<<"\n";break;
            }
            if(v[h.x]) continue;
            v[h.x]=1;
            if(edge.count(h.x))
            {
                for(auto i:edge[h.x])
                {
                    if(v[i.x]) continue;
                    q.push({h.v+i.v,i.x/*,h.t*100+i.x*/});
                }
            }
            //cout<<h.t<<" "<<h.v+w[y]<<"\n";//break;
        }

    }
    return 0;
}
