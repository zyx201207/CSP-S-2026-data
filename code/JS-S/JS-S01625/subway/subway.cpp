#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n=0,m,d,q;
    long long ans=INT_MAX;
    cin>>c>>n>>m>>d>>q;
    
    vector<int> wt(m+2);
    for(int i=1;i<=m;i++){
        cin>>wt[i];
    }
    vector< pair<int,int> > line[n+2];
    vector<int> k(n+2);
    vector< pair<int,int> > cline[m+2];
    for(int i=1;i<=n;i++){
        line[i].push_back({0,0});
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int t1,t2;
            cin>>t1>>t2;
            line[i].push_back({t1,t2});
            cline[t1].push_back({i,t2});
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        vector<short> vis(n+2,0);
        for(int j=0;j<cline[u].size();j++){
            vis[cline[u][j].first]=cline[u][j].second;
        }
        for(int j=0;j<cline[v].size();j++){
            long long cur=cline[v][j].first;
            long long w1=cline[v][j].second;
            if(vis[cur]!=0){
                int w2=vis[cur];
                ans=min(ans,w1+w2);
            }
        }
        cout<<ans+wt[u]+wt[v]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
