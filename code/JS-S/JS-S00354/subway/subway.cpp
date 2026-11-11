#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5,MAXN=2*500+5;
int w[MAXN];
vector<int>a[MAXN],t[MAXN];
struct edge{
    int to,val;
};
struct node{
    int u,dis;
};
vector<edge>e[MAXN];
typedef long long ll;
ll dis[MAXN];
bool operator <(node a,node b)
{
    return a.dis>b.dis;
}
void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    priority_queue<node>q;
    q.push((node){s,0});
    while(!q.empty())
    {
        node st=q.top();
        q.pop();
        for(auto ed:e[st.u])
        {
            ll new_dis=st.dis+ed.val;
            if(new_dis>dis[ed.to])
            {
                dis[ed.to]=new_dis;
                q.push((node){ed.to,dis[ed.to]});
            }

        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int aj,kj;
        cin>>aj>>kj;
        for(int j=2;j<=k;j++)
        {
            int ai,ti;
            cin>>ai>>ti;
            e[ai].push_back((edge){aj,0}),e[aj].push_back((edge){ai,0});
            e[ai].push_back((edge){500+ai,ti}),e[ai].push_back((edge){500+ai,ti});
            aj=ai,kj=ti;
        }
    }
    while(q--)
    {
        int xr,yr;
        cin>>xr>>yr;
        if(n==1) cout<<w[xr]+w[yr]<<endl;
        else
        {
            dij(xr+500);
            cout<<dis[yr+500]<<endl;
        }
    }
    return 0;
}
