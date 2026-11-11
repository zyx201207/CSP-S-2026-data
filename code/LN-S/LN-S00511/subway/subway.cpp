#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>w(m+5);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<int>k(n+5);
    vector<vector<int>>a(n+5),t(n+5);
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].reserve(k[i]+5);
        t[i].reserve(k[i]+5);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    vector<int>x(q+5),y(q+5);
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    vector<vector<pair<int,int>>>edge(501000);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            edge[i+500005].emplace_back(a[i][j],t[i][j]);
            edge[a[i][j]].emplace_back(i+500005,t[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int ans=w[x[i]]+w[y[i]];
        priority_queue<int,vector<int>,
        greater<int>>q;q.push(x[i]);
        vector<int>dis(501005,0x114514fc);
        dis[x[i]]=0;
        while((!q.empty())&&(dis[y[i]]==0x114514fc)){
            int o=q.top();
            q.pop();
            for(auto j:edge[o]){
                int ja=j.first,jb=j.second;
                if(dis[o]+jb<dis[ja]){
                    dis[ja]=dis[o]+jb;
                    q.push(ja);
                }
            }
        }
        cout<<dis[y[i]]+ans<<'\n';
    }
}