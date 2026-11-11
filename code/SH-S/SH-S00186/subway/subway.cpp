#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,tn,a,b;
bool find(const vector<vector<int>> &s,vector<bool> &vis,int curl,int curs){
    for(int i=0;i<n;i++)
        if(i!=curl&&s[i][curs]!=-1&&!vis[i])
        return true;
    return false;
}
int dfs(const vector<vector<int>> &s,vector<bool> &vis,int res,int curl,int curs){
    if(curs==b)
        return res;
    vis[curl]=true;
    if(s[curl][b]!=-1)
        return res;
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
        if(s[i][curs]!=-1&&!vis[i])
            ans=min(ans,dfs(s,vis,res+s[curl][curs]+s[i][curs],i,curs));
    for(int j=0;j<m;j++)
        if(j!=curs&&find(s,vis,curl,j))
            for(int i=0;i<n;i++)
                if(i!=curl&&s[i][curs]!=-1&&!vis[i])
                ans=min(ans,dfs(s,vis,res,i,j));
    vis[curl]=false;
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> ti(m);
    for(int i=0;i<m;i++)
        cin>>ti[i];
    vector<vector<int>> s(n,vector<int>(m,-1));
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>tn;
            cin>>s[t][tn];
        }
    }
    int ans=INT_MAX;
    while(q--){
        cin>>a>>b;
        for(int i=0;i<n;i++)
            if(s[i][a]!=-1){
                ans=min(ans,dfs(s,vis,0,i,a));
                vis=vector<bool>(n,false);
            }
        cout<<ans+ti[a]+ti[b];
    }
    return 0;
}
