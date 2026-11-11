#include<bits/stdc++.h>
using namespace std;//it's too HARD!!!
int c,n,m,d,q;
long long ans,a[501];
bool f[501];
vector<int> g[501],v[501];
void dfs(int p,int e,int t){
    if(t>ans) return;
    if(p==e)
    {
        ans=t;
        return;
    }
    f[p]=1;
    for(int i=0;i<g[p].size();i++)
    {
        if(f[g[p][i]]) continue;
        dfs(g[p][i],e,t+v[p][i]);
    }
    f[p]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int k,x[501],y[501];
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x[j]>>y[j];
            for(int cc=1;cc<j;cc++)
            {
                g[x[j]].push_back(x[cc]);
                g[x[cc]].push_back(x[j]);
                v[x[j]].push_back(y[j]+y[cc]);
                v[x[cc]].push_back(y[j]+y[cc]);
            }
        }
    }
    while(q--)
    {
        int iak,ioi;
        cin>>iak>>ioi;
        ans=114514191981011451ll;
        dfs(iak,ioi,0);
        cout<<ans+a[iak]+a[ioi]<<endl;
    }
    return 0;
}
