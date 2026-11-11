#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], a[500005], k, t[500005],x[500005],y[500005],sh[500005],ok[500005];
vector<pair<int,int>> G[500005];
int main()
{
    freopen("subway.in","r",stdin);
    //freopen("1.out","w",stdout);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int j=1;j<=k;++j)
            cin>>a[j]>>t[j];
        for(int j1=1;j1<k;++j1)
            for(int j2=j1+1;j2<=k;++j2){
                G[a[j1]].push_back({t[j1]+t[j2],a[j2]});
                G[a[j2]].push_back({t[j1]+t[j2],a[j1]});
            }
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > que;

    for(int i=1;i<=q;++i)
    {
        cin>>x[i]>>y[i];
        memset(sh,0x3f,sizeof(sh));
        memset(ok,0,sizeof(ok));
        sh[x[i]]=0;
        ok[x[i]]=1;
        que.push({0,x[i]});
        while(!que.empty())
        {
            auto top=que.top();
            que.pop();
            //cout<<top.first<<' '<<top.second<<endl;
            sh[top.second]=min(sh[top.second],top.first);
            ok[top.second]=1;
            if(top.second==y[i]){
                while(!que.empty())que.pop();
                break;
            }
            for(auto j:G[top.second]){
                if(ok[j.second]==0) {
                    que.push({j.first+top.first,j.second});
                }
            }
        }
        cout<<sh[y[i]]+w[x[i]]+w[y[i]]<<endl;
    }
    return 0;
}
