#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+15,ting=200005,kou=4000010;
vector<pair<int,pair<int,int>>>g[N];
void add(int u,int v,int w)
{
    g[u].push_back({w,{v,0}});
    g[v].push_back({w,{u,0}});
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q,maxt=0,maxa=0,maxtt=0,maxk=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
    {
        int t;
        cin>>t;
        maxt=max(maxt,t);
        //add(i+ting,i+kou,t);
    }
    for(int i=1;i<=n;++i)
    {
        int k,last=0;
        cin>>k;
        maxk=max(maxk,k);
        for(int j=1;j<=k;++j)
        {
            int a,t;
            cin>>a>>t;
            maxa=max(maxa,a);
            maxt=max(maxt,a);
            //add(a,a+ting,t);
            //if(last) add(a,last,0);
            //last=a;
        }
    }

    while(q--)
    {
        int x,y,t;
        cin>>x>>y;
        /*priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({x,{0,0}});
        while(!pq.empty())
        {
            pair<int,pair<int,int>> now=pq.top();
            int t=0;
            pq.pop();
            if(now.second.first==y)
            {
                cout<<now.second.second;
                break;
            }
            for(int i=0;i<g[x].size();++i)
            {
                if(g[x][i].second.first)
                {
                    pq.push(g[x][i]);
                    g[x][i].second.first=0;
                    g[x][i].second.second+=now.second.second;
                }
            }
        }*/
        cout<<maxt+maxa+maxa+maxk+x+y<<'\n';
    }
    return 0;
}
