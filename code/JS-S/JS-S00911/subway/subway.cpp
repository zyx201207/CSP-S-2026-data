#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int _,n,m,d,qq;
    cin>>_>>n>>m>>d>>qq;
    vector<int>v(m);
    vector<vector<int>>a(n),t(n),st(m);
    vector<unordered_map<int,int>>tm(m);
    for(int i=0;i<m;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i].resize(x);
        t[i].resize(x);
        for(int j=0;j<x;j++)cin>>a[i][j]>>t[i][j],a[i][j]--,st[a[i][j]].push_back(i),tm[a[i][j]][i]=t[i][j];
    }
    while(qq--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(x==y){
            cout<<"0\n";
            continue;
        }
        vector<int>vis(m+1,1e18);
        vis[x]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        for(auto c:st[x])q.push({0,{x,c}});
        while(q.size()){
            auto c=q.top();
            int dis=c.first,s=c.second.first,l=c.second.second;
            q.pop();
            for(auto cc:st[s]){
                for(auto c:a[cc])if(vis[c]>dis+tm[s][cc]+tm[c][cc]&&c!=s)vis[c]=dis+tm[s][cc]+tm[c][cc],q.push({vis[c],{c,cc}});
            }
        }
        cout<<vis[y]+v[x]+v[y]<<'\n';
    }
    return 0;
}
