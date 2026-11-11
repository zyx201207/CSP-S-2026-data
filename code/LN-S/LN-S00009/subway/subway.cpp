#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],f[500010];
map<pair<int,int>,int>a;
void bfs(int x)
{
    for(int i=1;i<=m;i++)
        f[i]=LLONG_MAX;
    queue<int>q;
    q.push(x);
    f[x]=0;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=1;i<=m;i++)
        {
            if(a[{i,t}]==0||f[t]==LLONG_MAX||i==t)continue;
            if(f[i]>f[t]+a[{i,t}])
            {
                f[i]=f[t]+a[{i,t}];
                q.push(i);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=i-1;j++)
            a[{i,j}]=0;
    for(int i=1;i<=n;i++)
    {
        int x,b[500010],t[500010];
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>b[j]>>t[j];
            for(int k=1;k<=j-1;k++)
            {
                a[{b[j],b[k]}]=t[j]+t[k];
                a[{b[k],b[j]}]=t[j]+t[k];
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        bfs(x);
        cout<<w[x]+w[y]+f[y]<<endl;
    }

}
